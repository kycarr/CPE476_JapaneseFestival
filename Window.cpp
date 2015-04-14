#include "Window.h"

Window::Window(
   int _width,
   int _height,
   const char* title) {
   // Default attribute values
   time = 0;
   frames = 0;
   dt = 0.0f;
   prev_time = 0.0;
   prev_frames = 0;
   prev_second = 0.0;

   // Defined attribute values
   width = _width;
   height = _height;

   // Initialise GLFW
   if (!glfwInit()) {
      fprintf( stderr, "Failed to initialize GLFW\n" );
      exit(-1);
   }
   glfwWindowHint(GLFW_SAMPLES, 4);
   glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

   glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);
   if (glfw_window == NULL) {
      fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
      glfwTerminate();
      exit(-1);
   }
   glfwMakeContextCurrent(glfw_window);

   glfwSetInputMode(glfw_window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we "hear" ESC
   glfwSetInputMode(glfw_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // Hide the mouse
}

Window::~Window() {
   glfwTerminate();
}

void Window::drawText(char* string, int x, int y) {
   // TODO
}

/**
 * @return Whether this window is still alive or has been closed by the user.
 */
bool Window::isActive() {
   return glfwGetKey(glfw_window, GLFW_KEY_ESCAPE) != GLFW_PRESS
      && glfwWindowShouldClose(glfw_window) == 0;
}

void Window::step() {
   glfwSwapBuffers(glfw_window);
   glfwPollEvents();

   time = glfwGetTime();
   frames++;
   dt = (float)(time - prev_time) / .01f; // TODO do we need '/ .01f'?

   // Check if a second has passed
   if (time - prev_second >= 1) {
      int df = frames - prev_frames;

      printf("%lf fps\n", df/(time - prev_second)); // TODO print FPS to window

      prev_frames = frames;
      prev_second = time;
   }

   prev_time = time;
}
