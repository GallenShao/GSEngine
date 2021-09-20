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
#include "parameter/layout.h"
#include "test_constants.h"
#include "utils/gs_gl_checker.h"

#include <sstream>

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

TEST(BufferTest, DumpVertexBuffer) {
  std::vector<float> vertex = TEST_VERTEX_BUFFER;
  auto vertex_ptr = std::make_shared<std::vector<float>>(std::move(vertex));
  auto buffer = new gs::backend::VertexBuffer(vertex_ptr);
  buffer->Dump();
  std::stringstream ss;
  ss << "[VertexBuffer] [" << buffer->GetId() << "] 1, 1, 0, 1, -1, 0, -1, -1, 0, -1, 1, 0";
  EXPECT_STREQ(gs::logger::last_log.c_str(), ss.str().c_str());
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

TEST(BufferTest, DumpIndexBuffer) {
  std::vector<uint32_t> index = TEST_INDEX_BUFFER;
  auto index_ptr = std::make_shared<std::vector<uint32_t>>(std::move(index));
  auto buffer = new gs::backend::IndexBuffer(index_ptr);
  buffer->Dump();
  std::stringstream ss;
  ss << "[IndexBuffer] [" << buffer->GetId() << "] 0, 1, 2, 2, 3, 0";
  EXPECT_STREQ(gs::logger::last_log.c_str(), ss.str().c_str());
  delete buffer;
}

TEST(BufferTest, CreateSimpleLayout0) {
  auto layout = gs::backend::Layout::GetSimpleLayout(0);
  EXPECT_EQ(layout->layout_items_.size(), 1);
  EXPECT_EQ(layout->total_size_, 3);
  EXPECT_STREQ(layout->layout_items_[0].name_.c_str(), "a_Position");
  EXPECT_EQ(layout->layout_items_[0].size_, 3);
  EXPECT_EQ(layout->layout_items_[0].offset_, 0);
}

TEST(BufferTest, CreateSimpleLayout1) {
  auto layout = gs::backend::Layout::GetSimpleLayout(1);
  EXPECT_EQ(layout->layout_items_.size(), 2);
  EXPECT_EQ(layout->total_size_, 5);
  EXPECT_STREQ(layout->layout_items_[0].name_.c_str(), "a_Position");
  EXPECT_EQ(layout->layout_items_[0].size_, 3);
  EXPECT_EQ(layout->layout_items_[0].offset_, 0);
  EXPECT_STREQ(layout->layout_items_[1].name_.c_str(), "v_texCoord0");
  EXPECT_EQ(layout->layout_items_[1].size_, 2);
  EXPECT_EQ(layout->layout_items_[1].offset_, 3);
}

TEST(BufferTest, CreateSimpleLayout2) {
  auto layout = gs::backend::Layout::GetSimpleLayout(2);
  EXPECT_EQ(layout->layout_items_.size(), 3);
  EXPECT_EQ(layout->total_size_, 7);
  EXPECT_STREQ(layout->layout_items_[0].name_.c_str(), "a_Position");
  EXPECT_EQ(layout->layout_items_[0].size_, 3);
  EXPECT_EQ(layout->layout_items_[0].offset_, 0);
  EXPECT_STREQ(layout->layout_items_[1].name_.c_str(), "v_texCoord0");
  EXPECT_EQ(layout->layout_items_[1].size_, 2);
  EXPECT_EQ(layout->layout_items_[1].offset_, 3);
  EXPECT_STREQ(layout->layout_items_[2].name_.c_str(), "v_texCoord1");
  EXPECT_EQ(layout->layout_items_[2].size_, 2);
  EXPECT_EQ(layout->layout_items_[2].offset_, 5);
}
