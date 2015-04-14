#ifndef __World__
#define __World__

#include "includes.h"

class World {
   public:
      World(
         vector<tinyobj::shape_t> &_shapes,
         vector<tinyobj::material_t> &_materials,
         GLint _h_uAClr,
         GLint _h_uDClr,
         GLint _h_uSClr,
         GLint _h_uS,
         GLint _h_uM,
         GLint _h_aPos,
         GLint _h_aNor);
      virtual ~World();

      void step(float dt);
      void draw();
      void initGround();
      void drawGround();
   private:
      vector<tinyobj::shape_t> shapes; // TODO map of mesh data
      vector<tinyobj::material_t> materials;
      GLint h_aPos, h_aNor;
      GLint h_uM;
      GLint h_uAClr, h_uDClr, h_uSClr, h_uS;
      bufID_t groundBufIDs;

      float randF();
      inline void safe_glUniformMatrix4fv(const GLint handle, const GLfloat data[]);
};

#endif