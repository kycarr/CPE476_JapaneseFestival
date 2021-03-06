#ifndef __World__
#define __World__

#include "includes.h"
#include "Object.h"
#include "Window.h"
#include "Camera.h"
#include "SkyBox.h"
#include "Booth.h"
#include "Particle.h"

#define NUM_FIREWORKS 25
#define NUM_FIREWORK_PARTICLES 50
#define FOUNTAIN_TTL 35.0f
#define COLOR_COUNT 6

struct Extra {
   Object* object;
   glm::vec3 startPos;
   glm::vec3 currPos;
   glm::vec3 targetPos;
   
   int i, j;
   
   int rest;
};
   

class World {
   public:
      int numCollected;

      World(GLuint ShadeProg, Camera* _camera);
      virtual ~World();

      void step(Window* window);
      void initGround();
      void drawGround();
      int numLeft();
      Booth* currentActiveBooth();
      void inMiniGame();
      void leftMiniGame();
      
      void initParticles(Program* prog);
      void particleStep(Program* prog, Window* window);
      
      bool drawWorld;
      vector<Booth*> booths;
      vector<Object*> structures;
      
   private:
      vector<tinyobj::shape_t> shapes; // TODO map of mesh data
      vector<struct Extra*> extras; // bunnies for now.
      vector<Object*> grass;
      vector<tinyobj::material_t> materials;
      vector<Particle*> fountainParticles;
      vector<Particle*> fireflyParticles;
      vector<vector<Particle*> > fireworkParticles;
      glm::vec3 fireworkPositions[(int)(SIZE * 8.0f)];
      
      glm::vec3 fireworkColors[COLOR_COUNT];
      
      Object* player;
      float playerXZRad;
      
      GLuint ShadeProg;
      GLint h_aPos, h_aNor;
      GLint h_uM;
      GLint h_uAClr, h_uDClr, h_uSClr, h_uS;
      GLint h_uTexUnit;
      double objStartTime;
      bool inGame;
      
      // time info for particles
      float t, t0_disp, t_disp;
      float h;
      glm::vec3 g;

      SkyBox* skybox;
      Object* ground;
      Camera* camera;
      int blerch;
      glm::vec3 mapGrid[(int)SIZE * 2 - 2][(int)SIZE * 2 - 2];

      inline void safe_glUniformMatrix4fv(const GLint handle, const GLfloat data[]);
      void createPlayer(const string &meshName, int texID);
      void createExtras(const string &meshName, int texID);
      void setupOverWorld();
      void drawOverWorld();
      bool detectSpawnCollision(Object* object);
      void calcExtraSpawnPosition(struct Extra* extra);
      void parseMapFile(const char* fileName);
      void drawObject(Object* obj);
      void extractViewFrustumPlanes(struct plane* planes, const glm::mat4 matrix);
      void normalizePlane(struct plane p);
      bool checkPlane(struct plane p, glm::vec3 pos, float rad);
      void findNewExtraTarget(struct Extra* extra);
      bool checkStructureCollisions(Object* object);
      bool checkBoothCollisions(Object* object);
      bool passedTarget(struct Extra* extra);
      void grassWave(Window* window);
};

#endif
