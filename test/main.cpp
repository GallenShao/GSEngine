/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * main.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gtest/gtest.h>

#include <iostream>

namespace gs::test {

class Environment : public ::testing::Environment {
 public:
  ~Environment() override = default;

  // Override this to define how to set up the environment.
  void SetUp() override {
    // Avoid reallocating static objects if called in subclasses of FooTest.
    if (window == nullptr) {
      /* Initialize the library */
      ASSERT_TRUE(glfwInit());
      glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
      /* Create a windowed mode window and its OpenGL context */
      window = glfwCreateWindow(1, 1, "GSEngineTest", nullptr, nullptr);
      if (!window) {
        glfwTerminate();
        ASSERT_TRUE(false);
      }
      /* Make the window's context current */
      glfwMakeContextCurrent(window);
    }
  }

  // Override this to define how to tear down the environment.
  void TearDown() override {
    glfwTerminate();
    window = nullptr;
  }

 private:
  GLFWwindow *window = nullptr;
};

}  // namespace gs::test

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  testing::AddGlobalTestEnvironment(new gs::test::Environment());
  return RUN_ALL_TESTS();
}