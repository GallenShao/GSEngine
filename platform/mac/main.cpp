#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "gs_engine.h"

int main() {
  GLFWwindow *window;
  /* Initialize the library */
  if (!glfwInit()) return -1;
  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  auto gs_engine = new gs::GSEngine();
  delete gs_engine;

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}