/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * shader.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include "shader.h"
#include "test_constants.h"

TEST(ShaderTest, CompileVertexShader) {
  auto shader = new gs::Shader(gs::ShaderType::Vertex, TEST_VERTEX_SHADER);
  EXPECT_NE(shader->GetId(), 0);
  delete shader;
}

TEST(ShaderTest, CompileFragmentShader) {
  auto shader = new gs::Shader(gs::ShaderType::Fragment, TEST_FRAGMENT_SHADER);
  EXPECT_NE(shader->GetId(), 0);
  delete shader;
}