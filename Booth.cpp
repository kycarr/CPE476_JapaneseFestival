#include "Booth.h"

using namespace std;

Booth::Booth(glm::vec3 _pos, glm::vec3 _scalar, float _angle, char* _minigame,
             vector<tinyobj::shape_t> shapes,
             vector<tinyobj::material_t> materials,
             GLuint ShadeProg) {
    
    // load the booth
    booth[0] = new Object(shapes, materials, ShadeProg);
    booth[0]->bumpy = true;
    booth[0]->load((char *)"objs/stall_top.obj");
    booth[0]->setShadows(true, 0.02, 1.0);
    booth[0]->setTexture(textures[TEX_WOOD_RED]);
    booth[0]->setNormalmap(textures[TEX_WOOD_NORM]);
    booth[1] = new Object(shapes, materials, ShadeProg);
    booth[1]->bumpy = true;
    booth[1]->load((char *)"objs/stall_mid.obj");
    booth[1]->setShadows(true, 0.021, 1.0);
    booth[1]->setTexture(textures[TEX_WOOD_DARK]);
    booth[1]->setNormalmap(textures[TEX_WOOD_NORM]);
    booth[2] = new Object(shapes, materials, ShadeProg);
    booth[2]->bumpy = true;
    booth[2]->load((char *)"objs/stall_bottom.obj");
    booth[2]->setShadows(true, 0.022, 1.0);
    booth[2]->setTexture(textures[TEX_WOOD_LIGHT]);
    booth[2]->setNormalmap(textures[TEX_WOOD_NORM]);
    initBooth(_pos, _scalar, _angle, _minigame);
    
    // initiate bounding box
    booth[1]->getBounds(&bounds);
    
    bumpRadius = 1.0f;
    interactRadius = 4.0f;
    active = false;
    interactMessage = NULL;
    decoration = NULL;
    
    if (strcmp(_minigame, "watermelon_smash") == 0) {
        decoration = new Object(shapes, materials, ShadeProg);
        decoration->load((char *)"objs/watermelon_slice.obj");
        decoration->setTexture(textures[TEX_MELON]);
        decoration->translate(glm::vec3(-10.0,2.3,17.0));
        decoration->rotate(0.0, glm::vec3(0.0f, 1.0f, 0.0f));
        decoration->scale(glm::vec3(3.0,3.0,3.0));
        decoration->setShadows(true, 0.023, 0.8);
    }
    else if (strcmp(_minigame, "shooting_gallery") == 0) {
        decoration = new Object(shapes, materials, ShadeProg);
        decoration->load((char *)"objs/target.obj");
        decoration->setTexture(textures[TEX_TARGET]);
        decoration->translate(glm::vec3(10.0,2.75,17.0));
        decoration->rotate(180.0, glm::vec3(0.0f, 1.0f, 0.0f));
        decoration->scale(glm::vec3(2.0,2.0,2.0));
        decoration->setShadows(true, 0.023, 0.8);
    }
    else if (strcmp(_minigame, "shop") == 0) {
        decoration = new Object(shapes, materials, ShadeProg);
        decoration->load((char *)"objs/bow.obj");
        decoration->setTexture(textures[TEX_GIRL_RED]);
        decoration->translate(glm::vec3(-10.0,2.4,-15.0));
        decoration->rotate(180.0, glm::vec3(0.0f, 1.0f, 0.0f));
        decoration->scale(glm::vec3(2.0,2.0,2.0));
        decoration->setShadows(true, 0.023, 0.8);
    }
}

void Booth::initBooth(glm::vec3 _pos, glm::vec3 _scalar, float _angle, char* _minigame) {
    float x0, y0, z0, x2, y2, z2;
    float s0, s2, angle;
    
    glm::vec3 bot_pos, top_pos, bot_scalar, top_scalar;
    
    top_pos = glm::vec3(_pos.x-0.05f, _pos.y+0.3f, _pos.z);
    bot_pos = glm::vec3(_pos.x, _pos.y-2.5f, _pos.z);
    
    top_scalar = _scalar*1.4667f;
    bot_scalar = _scalar*0.8f;
    
    // load the booth data
    strcpy(minigame, _minigame);
    // place the booths
    booth[0]->translate(top_pos);
    booth[0]->rotate(_angle, glm::vec3(0.0f, 1.0f, 0.0f));
    booth[0]->scale(top_scalar);
    booth[1]->translate(_pos);
    booth[1]->rotate(_angle, glm::vec3(0.0f, 1.0f, 0.0f));
    booth[1]->scale(_scalar);
    booth[2]->translate(bot_pos);
    booth[2]->rotate(_angle, glm::vec3(0.0f, 1.0f, 0.0f));
    booth[2]->scale(bot_scalar);
}

Booth::~Booth(){
    delete booth[0];
    delete booth[1];
    delete booth[2];
    if (decoration != NULL) {
        delete decoration;
        decoration = NULL;
    }
}

void Booth::draw() {
    booth[0]->draw();
    booth[1]->draw();
    booth[2]->draw();
    
    if (decoration != NULL)
        decoration->draw();
}

//Shows the message to the screen through whatever magic we're going to use
void Booth::showMessage() {
  //TODO magic to show messages on the screen without glut.
}

//Checks if anything is colliding with the booth so it stops them.
bool Booth::checkCollision(Object* _otherObject){
   booth[1]->checkCollision(_otherObject);
}

void Booth::getCollisionAxis(glm::vec3 pos, glm::vec3* colPlane) {
   booth[1]->getCollisionAxis(pos, colPlane);
}

// check for camera collision set colPlane equal to the bound that has been passed through
bool Booth::checkCameraCollision(glm::vec3 cam_pos, glm::vec3 *colPlane) {
   return booth[1]->checkCameraCollision(cam_pos, colPlane);
}

// check for player collision
bool Booth::checkPlayerCollision(Object* player, glm::vec3* colPlane) {
   return booth[1]->checkPlayerCollision(player, colPlane);
}

//Checks for if the player is within the interact radius
//Only returns true if type is BOOTH_TYPE
bool Booth::checkInteract(glm::vec3 player_pos){
   if ((player_pos.x < influence_bounds.x_min) || (player_pos.x > influence_bounds.x_max)) {
      active = false;
      return false;
   }
   if ((player_pos.y < influence_bounds.y_min) || (player_pos.y > influence_bounds.y_max)) {
      active = false;
      return false;
   }
   if ((player_pos.z < influence_bounds.z_min) || (player_pos.z > influence_bounds.z_max)) {
      active = false;
      return false;
   }
   
   //if it gets here, player exists in bounds
   if (!active) { // anything you only want done once, put here.
      active = true;
   }
   return false;
}

void Booth::calculateBoundingBox() {
   booth[2]->getBounds(&(booth[2]->bounds));
   booth[1]->getBounds(&bounds);
   influence_bounds.x_min = bounds.x_min - INFLUENCE_WIDTH;
   influence_bounds.x_max = bounds.x_max + INFLUENCE_WIDTH;
   influence_bounds.y_min = bounds.y_min;
   influence_bounds.y_max = bounds.y_max;
   influence_bounds.z_min = bounds.z_min - INFLUENCE_WIDTH;
   influence_bounds.z_max = bounds.z_max + INFLUENCE_WIDTH;
}

//Sets the position for the booth
void Booth::setPosition(glm::vec3 position){
    for (int i = 0; i < 3; i++) {
        booth[i]->setPos(position);
    }
}

// Return the minigame associated with this booth
char* Booth::getMinigame() {
   return minigame;
}

const string Booth::getMinigameDisplayName() {
   if (strcmp(minigame, SHOOTING_GALLERY) == 0)
      return "SHOOTING GALLERY";
   else if (strcmp(minigame, WATERMELON_SMASH) == 0)
      return "WATERMELON SMASH";
   else if (strcmp(minigame, KARAOKE) == 0)
      return "KARAOKE";
   else if (strcmp(minigame, SHOP) == 0)
      return "SHOP";
   else {
      // Booth doesn't have a minigame OR we haven't created a display name for it
      return "-- BOOTH UNDER CONSTRUCTION --";
   }
}

const string Booth::getMinigameSplash() {
   if (strcmp(minigame, SHOOTING_GALLERY) == 0)
      return "Press ENTER to play SHOOTING GALLERY";
   else if (strcmp(minigame, WATERMELON_SMASH) == 0)
      return "Press ENTER to play WATERMELON SMASH";
   else if (strcmp(minigame, KARAOKE) == 0)
      return "Press ENTER to play KARAOKE";
   else if (strcmp(minigame, SHOP) == 0)
      return "Press ENTER to SHOP";
   else {
      // Booth doesn't have a minigame OR we haven't created a display name for it
      return "-- BOOTH UNDER CONSTRUCTION --";
   }
}
