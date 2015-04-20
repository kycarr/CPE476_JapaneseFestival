#include "World.h"

static string objectFiles[] = {"bunny.obj"};

World::World(
      GLint _h_uAClr,
      GLint _h_uDClr,
      GLint _h_uSClr,
      GLint _h_uS,
      GLint _h_uM,
      GLint _h_aPos,
      GLint _h_aNor,
      GLint _h_uTexUnit,
      GLint _h_aTexCoord) {
   // Default attribute values
   objStartTime = 0.0;
   numCollected = 0;

   // Defined attribute values
   h_uAClr = _h_uAClr;
   h_uDClr = _h_uDClr;
   h_uSClr = _h_uSClr;
   h_uS = _h_uS;
   h_uM = _h_uM;
   h_aPos = _h_aPos;
   h_aNor = _h_aNor;

   //loadExtras();//objectFiles[0]);
   skybox = new SkyBox(h_aPos, h_aNor, h_uM, _h_uTexUnit, _h_aTexCoord);
   initGround();
   setupOverWorld();
}

World::~World() {
   for (int i=0; i<objects.size(); ++i) { 
      delete objects[i];
   }
   for (int i=0; i<extras.size(); ++i) { 
      delete extras[i];
   }
}

void World::step(Camera *camera, Window* window) {
   // Create a new object every SECS_PER_OBJ
   if (numLeft() < MAX_OBJS && window->time - objStartTime >= SECS_PER_OBJ) {
      createExtra(EXTRA_FILE_NAME);
      objStartTime = window->time;
   }

// TODO I know I said looping with ints is bad but this link below proved otherwise. Use it if getting segfaults
// http://gamedev.stackexchange.com/questions/46584/how-to-remove-an-object-from-a-stdvector
   /*for (int i=0; i<activeObjects.size(); ++i) { 
      Object* obj1 = activeObjects[i];
      if (obj1->collidedWithPlayer(camera->calcNewPos(window), window->dt)) {
         // Delete object from collision detection
         activeObjects[i] = activeObjects.back();
         activeObjects.pop_back();
         --i;
         continue;
      }
      if (obj1->collidedWithWall(window->dt)) {
         continue;
      }
      for (int j=0; j<activeObjects.size(); ++j) { 
         Object* obj2 = activeObjects[j];
         if (obj1 == obj2) {
            continue;
         }
         if (obj1->collidedWithObj(*obj2, window->dt)) {
            break;
         }
      }
   }

   for (int i=0; i<objects.size(); ++i) { 
      bject* obj = objects[i];
      // If the object has finished shrinking, remove it
      if (obj->radius <= 0.0) {
         objects[i] = objects.back();
         objects.pop_back();
         --i;
         delete obj;
         // Increment the score
         numCollected++;
         continue;
      }
      if (obj->collidedWithPlayer(camera->calcNewPos(window), window->dt)) {
         // Stop the camera from moving into object
         camera->blocked = true;
      }
      // Update the object normally
      obj->step(window->dt);
   }*/
   for (int i=0; i<extras.size(); ++i) {
      Object* extra = extras[i];
      extra->step(window->dt);
   }

   camera->step(window);
   skybox->draw(camera);
   drawGround();
   drawOverWorld();
}

inline void World::safe_glUniformMatrix4fv(const GLint handle, const GLfloat data[]) {
   if (handle >= 0)
      glUniformMatrix4fv(handle, 1, GL_FALSE, data);
}

void World::initGround() {
   // Position array of ground
   GLfloat vertices[] = {
      -1.0f, 0.0, -1.0f, //0
      -1.0f, 0.0, +1.0f, //1
      +1.0f, 0.0, -1.0f, //2
      +1.0f, 0.0, +1.0f, //3
   };
   // Amplify ground size
   for (int i = 0, last = sizeof(vertices)/sizeof(GLfloat); i < last; i++) {
      // Don't amplify the floor height
      if (i % 3 != 1)
         vertices[i] *= SIZE;
   }
   glGenBuffers(1, &(groundBufIDs.pos));
   glBindBuffer(GL_ARRAY_BUFFER, groundBufIDs.pos);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   // Index array of ground
   GLuint indices[] = {
      0, 1, 2,
      1, 3, 2,
   };
   glGenBuffers(1, &(groundBufIDs.ind));
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, groundBufIDs.ind);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

   // Normal array of ground
   vector<float> posBuf(vertices, vertices+sizeof(vertices)/sizeof(vertices[0]));
   vector<unsigned int> indBuf(indices, indices+sizeof(indices)/sizeof(indices[0]));

   glGenBuffers(1, &(groundBufIDs.nor));
   glBindBuffer(GL_ARRAY_BUFFER, groundBufIDs.nor);
}

void World::drawGround() {
   // Bind position buffer
   glBindBuffer(GL_ARRAY_BUFFER, groundBufIDs.pos);
   glVertexAttribPointer(h_aPos, 3, GL_FLOAT, GL_FALSE, 0, 0);
   // Bind index buffer
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, groundBufIDs.ind);
   // Bind normal buffer
   glVertexAttribPointer(h_aNor, 3, GL_FLOAT, GL_FALSE, 0, 0);
   // Set color
   glUniform3f(h_uAClr, 0.13, 0.13, 0.14);
   glUniform3f(h_uDClr, 0.0, 0.0, 0.0);
   glUniform3f(h_uSClr, 0.0, 0.0, 0.0);
   glUniform1f(h_uS, 1.0);
   // Apply translation
   glm::vec3 trans = glm::vec3(0.0, 0.0f, 0.0);
   glm::mat4 T = glm::translate(glm::mat4(1.0f), trans);
   safe_glUniformMatrix4fv(h_uM, glm::value_ptr(T));

   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void World::drawOverWorld() {
   for (int i=0; i<structures.size(); ++i) {
      Object* structure = structures[i];
      structure->draw();
   }
}

void World::setupOverWorld() {
   Object* box = new Object(shapes, materials, h_uAClr, h_uDClr, h_uSClr, h_uS, h_uM, h_aPos, h_aNor);
   box->load(WALL_FILE_NAME);
   box->translate(glm::vec3(-10.0f, 1.0f, 0.0f));
   //box->rotate(45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
   
   structures.push_back(box);
   
   Object* booth = new Object(shapes, materials, h_uAClr, h_uDClr, h_uSClr, h_uS, h_uM, h_aPos, h_aNor);
   booth->load(WALL_FILE_NAME);
   booth->translate(glm::vec3(10.0f, 1.0f, 0.0f));
   //box->rotate(45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
   structures.push_back(booth);
}

void World::createExtra(const string &meshName) {
   Object* extra = new Object(shapes, materials, h_uAClr, h_uDClr, h_uSClr, h_uS, h_uM, h_aPos, h_aNor);
   extra->load(meshName);
   extra->setPos(glm::vec3(2*Util::randF()*SIZE - SIZE, 1.0, 2*Util::randF()*SIZE - SIZE));
   extra->setDir(glm::normalize(glm::vec3(Util::randF()-0.5, 0.0, Util::randF()-0.5)));
   extra->setSpeed(OBJ_SPEED);
   extras.push_back(extra);
}

int World::numLeft() {
   return extras.size();
}
