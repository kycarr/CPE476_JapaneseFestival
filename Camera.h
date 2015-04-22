#ifndef __Camera__
#define __Camera__

#include "includes.h"
#include "Window.h"

// Minigame locations
#define MINIGAME_LOC glm::vec3(20*SIZE, 2, 0)

class Camera {
   public:
      bool bounded;
      float speed;
      glm::vec3 pos;
      bool blocked;
      bool pov;

      Camera(
         GLint _h_uP,
         GLint _h_uV,
         GLint _h_uView);
      virtual ~Camera();

      float getYRot();
      void toggleBounded();
      glm::vec3 lookAtPt();
      void setProjectionMatrix(int g_width, int g_height);
      void setView();
      void step(Window* window);
      void mouse_callback(GLFWwindow* window, double xpos, double ypos, int g_width, int g_height);
      void enter_callback(GLFWwindow* window, int entered, int g_width, int g_height);
      glm::vec3 calcNewPos(Window* window);
      void moveToMinigame();
   private:
      float theta;
      float phi;
      GLint h_uP;
      GLint h_uV;
      GLint h_uView;
      bool playingMinigame;

      inline void safe_glUniformMatrix4fv(const GLint handle, const GLfloat data[]);
};

#endif
