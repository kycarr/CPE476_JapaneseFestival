#include "Object.h"

Object::Object(
      vector<tinyobj::shape_t> &_shapes,
      vector<tinyobj::material_t> &_materials,
      GLuint _ShadeProg)  :
	      posBufID(0),
	      norBufID(0),
	      indBufID(0) {
	      
   // Default attribute values
   collected = false;
   shine = 800.0;
   radius = OBJ_SIZE;
   
   // initialize transform matrices
   //printf("modelMat initialized\n");
   modelMat = glm::mat4(1.0f);
   scalerMat = glm::mat4(1.0f);
   rotateMat = glm::mat4(1.0f);
   transMat = glm::mat4(1.0f);
   
   boundBoxScalerMat = glm::scale(glm::mat4(1.0f), glm::vec3(1.1f,1.1f,1.1f));

   // Defined attribute values
   shapes = _shapes;
   materials = _materials;
   ShadeProg = _ShadeProg;
   h_uM = GLSL::getUniformLocation(ShadeProg, "uM");
   h_aPos = GLSL::getAttribLocation(ShadeProg, "aPos");
   h_aNor = GLSL::getAttribLocation(ShadeProg, "aNor");

   pos = glm::vec3(0.0f, 0.0f, 0.0f);
   dimensions = glm::vec3(1.0f, 1.0f, 1.0f);
   dir = glm::vec3(0.0f, 0.0f, 0.0f);
   vel = 0.0f;
   
   directional = false;
   castShadows = true;
   setTexture(MISC_TYPE);
}

Object::~Object() {}

// scale object by flat amount, applied on top of scaling done by the radius
void Object::scale(glm::vec3 scaler) {
   scalerMat = glm::scale(glm::mat4(1.0f), scaler);
   radius = glm::max(glm::max(scaler.x, scaler.y), scaler.z);
}

// rotate object by flat amount, this will be applied on top of directional rotations
void Object::rotate(float angle, glm::vec3 axis) {
   rotateMat = glm::rotate(glm::mat4(1.0f), angle, axis);
}

// translate object by flat amount... this will be applied on top of positional translations
void Object::translate(glm::vec3 trans) {
   transMat = glm::translate(glm::mat4(1.0f), trans);
}

bool Object::collidedWithPlayer(glm::vec3 camPos, float dt) {
   glm::vec3 testPos = calculateNewPos(dt);
   
   if (glm::distance(testPos, camPos) <= radius) {
      vel = 0;
      collected = true;
      return true;
   }
   else {
      return false;
   }
}

bool Object::collidedWithWall(float dt) {
   bool collidedWithWall = false;
   glm::vec3 testPos = calculateNewPos(dt);
   
   // Check boundaries
   if (testPos.x < -SIZE
      || testPos.x > SIZE) {
      dir.x = -dir.x;
      collidedWithWall = true;
   }
   if (testPos.z < -SIZE 
      || testPos.z > SIZE) {
      dir.z = -dir.z;
      collidedWithWall = true;
   }

   return collidedWithWall;
}

bool Object::collidedWithObj(Object o, float dt) {
   glm::vec3 testPos = calculateNewPos(dt);
   glm::vec3 testPosO = o.calculateNewPos(dt);

   if (glm::distance(testPos, testPosO) <= (radius + o.radius)) {
      dir = -dir;
      
      return true;
   }
   else {
      return false;
   }
}

bool Object::collision(Object* o) {
   if (glm::distance(o->pos, pos) <= (radius + o->radius)) {
      return true;
   }
   return false;
}

float Object::getXZRadius() {
   const vector<float> &posBuf = shapes[0].mesh.positions;
   
   float xz_rad;
   for (int i = 0; i < (int)posBuf.size(); i += 3) {
      glm::vec4 v;
      v = glm::vec4(posBuf[i], posBuf[i+1], posBuf[i+2], 1.0f) * scalerMat;
      if (i == 0) {
         // initialize radius on first pass
         xz_rad = abs(v.x);
      }
      else {
         if (abs(v.x) > xz_rad) {
            xz_rad = abs(v.x);
         }
         if (abs(v.z) > xz_rad) {
            xz_rad = abs(v.z);
         }
      }
   }
   return xz_rad;
}

//Checks if anything is colliding with the object so it stops them.
bool Object::checkCollision(Object* _otherObject){
   glm::vec3 max = glm::vec3(_otherObject->getPos().x + _otherObject->getRadius(), _otherObject->getPos().y + _otherObject->getRadius(), _otherObject->getPos().z + _otherObject->getRadius());
   glm::vec3 min = glm::vec3(_otherObject->getPos().x - _otherObject->getRadius(), _otherObject->getPos().y - _otherObject->getRadius(), _otherObject->getPos().z - _otherObject->getRadius());
   
   if ((max.x < bounds.x_min) || (min.x > bounds.x_max)) {
      return false;
   }
   if ((max.y < bounds.y_min) || (min.y > bounds.y_max)) {
      return false;
   }
   if ((max.z < bounds.z_min) || (min.z > bounds.z_max)) {
      return false;
   }
   
   return true;
}

void Object::getCollisionAxis(glm::vec3 pos, glm::vec3* colPlane) {
   float x_diff, y_diff, z_diff;
   x_diff = bounds.x_min - pos.x;
   if (abs(bounds.x_max - pos.x) < abs(x_diff)) {
      x_diff = bounds.x_max - pos.x;
   }
   y_diff = bounds.y_min - pos.y;
   if (abs(bounds.y_max - pos.y) < abs(y_diff)) {
      y_diff = bounds.y_max - pos.y;
   }
   z_diff = bounds.z_min - pos.z;
   if (abs(bounds.z_max - pos.z) < abs(z_diff)) {
      z_diff = bounds.z_max - pos.z;
   }
   
   float diffs[3] = {x_diff, y_diff, z_diff};
   float min = abs(diffs[0]);
   glm::vec3 plane = glm::vec3(1.0f, 0.0f, 0.0f);
   for (int i=0; i<3; ++i) {
      if (abs(diffs[i]) < min) {
         min = abs(diffs[i]);
         plane = glm::vec3(0.0f);
         plane[i] = 1.0f;
      }
   }
   glm::vec3 temp_vec = glm::vec3(pos.x + x_diff, pos.y + y_diff, pos.z + z_diff);
   plane *= temp_vec;
   colPlane->x = plane.x;
   colPlane->y = plane.y;
   colPlane->z = plane.z;
}

// check for camera collision set colPlane equal to the bound that has been passed through
bool Object::checkCameraCollision(glm::vec3 cam_pos, glm::vec3 *colPlane) {
   if ((cam_pos.x < bounds.x_min) || (cam_pos.x > bounds.x_max)) {
      return false;
   }
   if ((cam_pos.y < bounds.y_min) || (cam_pos.y > bounds.y_max)) {
      return false;
   }
   if ((cam_pos.z < bounds.z_min) || (cam_pos.z > bounds.z_max)) {
      return false;
   }
   
   getCollisionAxis(cam_pos, colPlane);
   
   return true;
}

// check for player collision
bool Object::checkPlayerCollision(Object* player, glm::vec3* colPlane) {
   if (!checkCollision(player)) {
      return false;
   }
   
   getCollisionAxis(player->getPos(), colPlane);
   return true;
}

void Object::getBounds(struct bound_box *_bounds) {
   
   float x_min, x_max, y_min, y_max, z_min, z_max; 
   const vector<float> &posBuf = shapes[0].mesh.positions;
	for(int i = 0; i < (int)posBuf.size(); i += 3) {
      glm::vec4 v;
      v = glm::vec4(posBuf[i], posBuf[i+1], posBuf[i+2], 1.0f);
      v = modelMat * v;
      if (i == 0) { 
         // initialize _bounds on first pass
         x_min = x_max = v.x;
         y_min = y_max = v.y;
         z_min = z_max = v.z;
      }
      else {
         // establish spatial relationships
         if (v.x < x_min) {
            x_min = v.x;
         }
         else if (v.x > x_max) {
            x_max = v.x;
         }
         if (v.y < y_min) {
            y_min = v.y;
         }
         else if (v.y > y_max) {
            y_max = v.y;
         }
         if (v.z < z_min) {
            z_min = v.z;
         }
         else if (v.z > z_max) {
            z_max = v.z;
         }
      }
   }
    
   _bounds->x_min = x_min;
   _bounds->x_max = x_max;
   _bounds->y_min = y_min;
   _bounds->y_max = y_max;
   _bounds->z_min = z_min;
   _bounds->z_max = z_max;
   
   memcpy(&bounds, _bounds, sizeof(bounds));
}

void Object::step(float dt) {
   draw();
}

/**
 * @return Rotation angle to face in degrees (0-360) along Y-axis.
 */
float Object::calcYFacingAngle() {
   float radians = atan(dir.z/dir.x);

   if (dir.x < 0) {
      radians = 180 - radians;
   }

   if (dir.x > 0 && dir.z < 0) {
      radians = 360 - radians;
   }

   return radians * (180.0 / M_PI); // Convert to degrees
}

void Object::load(const string &meshName)
{
    std::vector<tinyobj::material_t> objMaterials;
    string err = tinyobj::LoadObj(shapes, objMaterials, meshName.c_str());
    if(!err.empty()) {
        cerr << err << endl;
    }
    
    // Scale the vertex positions so that they fit within [-1, +1] in all three dimensions.
    vector<float> &posBuf = shapes[0].mesh.positions;
    
    glm::vec3 vmin(posBuf[0], posBuf[1], posBuf[2]);
    glm::vec3 vmax(posBuf[0], posBuf[1], posBuf[2]);
    for(int i = 3; i < (int)posBuf.size(); i += 3) {
        glm::vec3 v(posBuf[i], posBuf[i+1], posBuf[i+2]);
        vmin.x = min(vmin.x, v.x);
        vmin.y = min(vmin.y, v.y);
        vmin.z = min(vmin.z, v.z);
        vmax.x = max(vmax.x, v.x);
        vmax.y = max(vmax.y, v.y);
        vmax.z = max(vmax.z, v.z);
    }
    glm::vec3 center = 0.5f*(vmin + vmax);
    glm::vec3 diff = vmax - vmin;
    float diffmax = diff.x;
    diffmax = max(diffmax, diff.y);
    diffmax = max(diffmax, diff.z);
    float scale = 1.0f / diffmax;
    
    //transBuf.resize((int)(posBuf.size()/3));
    //int j = 0;
    for(int i = 0; i < (int)posBuf.size(); i += 3) {
        posBuf[i  ] = (posBuf[i  ] - center.x) * scale;
        posBuf[i+1] = (posBuf[i+1] - center.y) * scale;
        posBuf[i+2] = (posBuf[i+2] - center.z) * scale;
    }
    
    init();
}
 
void Object::load(const string &meshName, const string &matName)
{
	std::vector<tinyobj::material_t> objMaterials;
	string err = tinyobj::LoadObj(shapes, objMaterials, meshName.c_str(), matName.c_str());
	if(!err.empty()) {
		cerr << err << endl;
	}
	
	// Scale the vertex positions so that they fit within [-1, +1] in all three dimensions.
	vector<float> &posBuf = shapes[0].mesh.positions;
	
	glm::vec3 vmin(posBuf[0], posBuf[1], posBuf[2]);
	glm::vec3 vmax(posBuf[0], posBuf[1], posBuf[2]);
	for(int i = 3; i < (int)posBuf.size(); i += 3) {
		glm::vec3 v(posBuf[i], posBuf[i+1], posBuf[i+2]);
		vmin.x = min(vmin.x, v.x);
		vmin.y = min(vmin.y, v.y);
		vmin.z = min(vmin.z, v.z);
		vmax.x = max(vmax.x, v.x);
		vmax.y = max(vmax.y, v.y);
		vmax.z = max(vmax.z, v.z);
	}
	glm::vec3 center = 0.5f*(vmin + vmax);
	glm::vec3 diff = vmax - vmin;
	float diffmax = diff.x;
	diffmax = max(diffmax, diff.y);
	diffmax = max(diffmax, diff.z);
	float scale = 1.0f / diffmax;
	
	for(int i = 0; i < (int)posBuf.size(); i += 3) {
		posBuf[i  ] = (posBuf[i  ] - center.x) * scale;
		posBuf[i+1] = (posBuf[i+1] - center.y) * scale;
		posBuf[i+2] = (posBuf[i+2] - center.z) * scale;
   }
	
   init();
}

/* initialize a new shape */
void Object::init()
{
	// Send the position array to the GPU
	const vector<float> &posBuf = shapes[0].mesh.positions;
	glGenBuffers(1, &posBufID);
	glBindBuffer(GL_ARRAY_BUFFER, posBufID);
	glBufferData(GL_ARRAY_BUFFER, posBuf.size()*sizeof(float), &posBuf[0], GL_STATIC_DRAW);
	
	// Send the index array to the GPU
	const vector<unsigned int> &indBuf = shapes[0].mesh.indices;
	glGenBuffers(1, &indBufID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indBufID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indBuf.size()*sizeof(unsigned int), &indBuf[0], GL_STATIC_DRAW);
	
	// Send the normal array (if it exists) to the GPU
	const vector<float> norBuf = computeNormals(posBuf, indBuf);
	if(!norBuf.empty()) { 
		glGenBuffers(1, &norBufID);
		glBindBuffer(GL_ARRAY_BUFFER, norBufID);
		glBufferData(GL_ARRAY_BUFFER, norBuf.size()*sizeof(float), &norBuf[0], GL_STATIC_DRAW);
	} else {
	   printf("Uh Oh: normal buffer is empty\n");
		norBufID = 0;
	}
	
    // Send the texture coordinate array (if it exists) to the GPU
    const vector<float> texBuf = shapes[0].mesh.texcoords;
    if (!texBuf.empty()) {
        glGenBuffers(1, &texBufID);
        glBindBuffer(GL_ARRAY_BUFFER, texBufID);
        glBufferData(GL_ARRAY_BUFFER, texBuf.size() * sizeof(float), &texBuf[0], GL_STATIC_DRAW);
    } else {
        texBufID = 0;
    }
    
	// Unbind the arrays
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Object::draw()
{
   // Bind the texture
   glEnable(GL_TEXTURE_2D);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   glActiveTexture(GL_TEXTURE0);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glBindTexture(GL_TEXTURE_2D, texture_id);
    
	// Enable and bind position array for drawing
	GLSL::enableVertexAttribArray(h_aPos);
	glBindBuffer(GL_ARRAY_BUFFER, posBufID);
	glVertexAttribPointer(h_aPos, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// Enable and bind normal array (if it exists) for drawing
	if(norBufID) {
		GLSL::enableVertexAttribArray(h_aNor);
		glBindBuffer(GL_ARRAY_BUFFER, norBufID);
		glVertexAttribPointer(h_aNor, 3, GL_FLOAT, GL_FALSE, 0, 0);
	}
	// Bind index array for drawing
	int nIndices = (int)shapes[0].mesh.indices.size();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indBufID);
    // Enable and bind texture coordinate array (if it exists) for drawing
    if (texBufID) {
        GLint h_tex = GLSL::getAttribLocation(ShadeProg, "aTexCoord");
        GLSL::enableVertexAttribArray(h_tex);
        glBindBuffer(GL_ARRAY_BUFFER, texBufID);
        glVertexAttribPointer(h_tex, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }
	
   // Set the model transformation
   glm::vec3 position = pos + glm::vec3(0.0f, -0.5f, 0.0f);
   glm::mat4 T = glm::translate(glm::mat4(1.0f), position) * transMat;
   glm::mat4 R = rotateMat;
   if (directional) {
      glm::mat4 RX = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(1.0, 0.0, 0.0));
      glm::mat4 RY = glm::rotate(glm::mat4(1.0f), calcYFacingAngle(), glm::vec3(0.0, 1.0, 0.0));
      glm::mat4 RZ = glm::rotate(glm::mat4(1.0f), 0.0f, glm::vec3(0.0, 0.0, 1.0));
      R *= RX*RY*RZ;
   }
   modelMat = T*R*scalerMat;//S;
   
    // Draw the object
    Util::safe_glUniformMatrix4fv(h_uM, glm::value_ptr(T*R*scalerMat));
    glDrawElements(GL_TRIANGLES, nIndices, GL_UNSIGNED_INT, 0);
    
    // Draw the shadow
    if (castShadows) {
        glBindTexture(GL_TEXTURE_2D, 0);
        glm::mat4 sT = glm::translate(glm::mat4(1.0f), glm::vec3(0, -.4, 0));
        Util::safe_glUniformMatrix4fv(h_uM, glm::value_ptr(sT*ShadowMatrix()*T*R*scalerMat));
        glDrawElements(GL_TRIANGLES, nIndices, GL_UNSIGNED_INT, 0);
    }
}

vector<float> Object::computeNormals(vector<float> posBuf, vector<unsigned int> indBuf) {
   vector<float> norBuf;
   vector<glm::vec3> crossBuf;
   int idx1, idx2, idx3;
   glm::vec3 v1, v2, v3;
   glm::vec3 vec1, vec2, vec3;
   glm::vec3 cross1, cross2, cross3;

   // For every vertex initialize a normal to 0
   for (int j = 0; j < posBuf.size()/3; j++) {
      norBuf.push_back(0);
      norBuf.push_back(0);
      norBuf.push_back(0);

      crossBuf.push_back(glm::vec3(0, 0, 0));
   }

   // Compute normals for every face then add them to every associated vertex
   for (int i = 0; i < indBuf.size()/3; i++) {
      idx1 = indBuf[3*i+0];
      idx2 = indBuf[3*i+1];
      idx3 = indBuf[3*i+2];
      v1 = glm::vec3(posBuf[3*idx1 +0], posBuf[3*idx1 +1], posBuf[3*idx1 +2]); 
      v2 = glm::vec3(posBuf[3*idx2 +0], posBuf[3*idx2 +1], posBuf[3*idx2 +2]); 
      v3 = glm::vec3(posBuf[3*idx3 +0], posBuf[3*idx3 +1], posBuf[3*idx3 +2]); 

      vec1 = glm::normalize(v1 - v2);
      vec2 = glm::normalize(v2 - v3);
      vec3 = glm::normalize(v3 - v1);

      cross1 = glm::cross(vec1, vec2);
      cross2 = glm::cross(vec2, vec3);
      cross3 = glm::cross(vec3, vec1);

      crossBuf[idx1] += cross1;
      crossBuf[idx2] += cross2;
      crossBuf[idx3] += cross3;
   }

   // Cross products have been added together, normalize them and add to normal buffer
   for (int i = 0; i < indBuf.size()/3; i++) {
      idx1 = indBuf[3*i+0];
      idx2 = indBuf[3*i+1];
      idx3 = indBuf[3*i+2];

      cross1 = glm::normalize(crossBuf[idx1]);
      cross2 = glm::normalize(crossBuf[idx2]);
      cross3 = glm::normalize(crossBuf[idx3]);

      norBuf[3*idx1+0] = cross1.x;
      norBuf[3*idx1+1] = cross1.y;
      norBuf[3*idx1+2] = cross1.z;
      norBuf[3*idx2+0] = cross2.x;
      norBuf[3*idx2+1] = cross2.y;
      norBuf[3*idx2+2] = cross2.z;
      norBuf[3*idx3+0] = cross3.x;
      norBuf[3*idx3+1] = cross3.y;
      norBuf[3*idx3+2] = cross3.z;
   }

   return norBuf;
}

glm::mat4 Object::getModelMatrix() {
   return modelMat;
}
