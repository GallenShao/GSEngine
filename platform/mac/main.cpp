#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "gs_engine.h"

int main() {
  GLFWwindow *window;
  /* Initialize the library */
  if (!glfwInit()) return -1;
  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "GSEngineExample", nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  auto gs_engine = new gs::GSEngine();

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    /* Poll for and process events */
    glfwPollEvents();
  }

  delete gs_engine;

  glfwTerminate();
  return 0;
}