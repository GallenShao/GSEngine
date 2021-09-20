/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_renderer.cpp
 *
 *  Created on: 2021.09.21
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include "renderer.h"
#include "test_constants.h"
#include "utils/gs_gl_checker.h"

TEST(RenderTest, CreateRenderer) {
  std::vector<float> vertex = TEST_VERTEX_BUFFER;
  auto vertex_ptr = std::make_shared<std::vector<float>>(std::move(vertex));
  auto layout = gs::backend::Layout::GetSimpleLayout(0);
  auto vertex_parameter = std::make_shared<gs::backend::VertexParameter>(vertex_ptr, layout);

  std::vector<uint32_t> index = TEST_INDEX_BUFFER;
  auto index_ptr = std::make_shared<std::vector<uint32_t>>(std::move(index));
  auto index_parameter = std::make_shared<gs::backend::IndexParameter>(index_ptr);

  auto renderer = std::make_shared<gs::backend::Renderer>(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  renderer->SetVertices(vertex_parameter);
  renderer->SetIndices(index_parameter);
  renderer->SetUniforms(TEST_UNIFORM2, 0.5);
  renderer->SetUniforms(TEST_UNIFORM, 1.0, 1.0, 0.0, 1.0);
  renderer->Render();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}