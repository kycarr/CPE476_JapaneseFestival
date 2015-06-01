#ifndef __ShootingGallery__
#define __ShootingGallery__

#include "includes.h"
#include "Clicks.h"
#include "Texture.h"
#include "Window.h"
#include "Sound.h"
#include "FontEngine.h"

#define DEPTH 3.0
#define BULLET_SPD 20.0
#define ROWS 2
#define COLS 4

class ShootingGallery {
   public:
      ShootingGallery(GLuint _ShadeProg, Sound* _sound);
      virtual ~ShootingGallery();
      void mouseClick(glm::vec3 direction, glm::vec4 point);
      void mouseMove(double xpos, double ypos, int width, int height);
      void step(Window* window);

      bool gameOver, gameStart;

   private:
      vector<Object*> targets;
      vector<tinyobj::shape_t> shapes;
      vector<tinyobj::material_t> materials;
      
      float xRotation, yRotation;
      
      GLuint ShadeProg;
      Sound* sound;
      Object* wall;
      Object* gun;
      int score;
      double elapsedTime;
      void newTarget();
      vector<Object*> bullets;
      int ammo;
      float doneTimer;
      float timeLimit;
      void finished();
      void exit();
      void printInstructions();
      void textStep(Window* window);
      Object* tempFix; // Permament target that is off screen so background doesn't flicker
};

#endif
