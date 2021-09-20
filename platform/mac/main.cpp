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

  auto gs_engine = std::make_shared<gs::GSEngine>();

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    gs_engine->flush();

    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    /* Poll for and process events */
    glfwPollEvents();
  }

  gs_engine = nullptr;

  glfwTerminate();
  return 0;
}