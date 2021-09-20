/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_buffer.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include "buffer/index_buffer.h"
#include "buffer/vertex_buffer.h"
#include "test_constants.h"
#include "utils/gs_gl_checker.h"

TEST(BufferTest, CreateVertexBuffer) {
  std::vector<float> vertex = TEST_VERTEX_BUFFER;
  auto vertex_ptr = std::make_shared<std::vector<float>>(std::move(vertex));
  auto buffer = new gs::backend::VertexBuffer(vertex_ptr);
  EXPECT_NE(buffer->GetId(), 0);
  buffer->active();
  buffer->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
  delete buffer;
}

TEST(BufferTest, CreateIndexBuffer) {
  std::vector<uint32_t> index = TEST_INDEX_BUFFER;
  auto index_ptr = std::make_shared<std::vector<uint32_t>>(std::move(index));
  auto buffer = new gs::backend::IndexBuffer(index_ptr);
  EXPECT_NE(buffer->GetId(), 0);
  buffer->active();
  buffer->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
  delete buffer;
}
