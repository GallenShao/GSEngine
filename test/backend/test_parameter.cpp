/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_buffer.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include <sstream>

#include "parameter/index_parameter.h"
#include "parameter/layout.h"
#include "parameter/vertex_parameter.h"
#include "test_constants.h"
#include "utils/gs_gl_checker.h"

TEST(ParameterTest, CreateSimpleLayout0) {
  auto layout = gs::backend::Layout::GetSimpleLayout(0);
  EXPECT_EQ(layout->layout_items_.size(), 1);
  EXPECT_EQ(layout->total_size_, 3);
  layout->Dump();
  EXPECT_STREQ(gs::logger::last_log.c_str(), "[Layout] a_Position(3) ");
}

TEST(ParameterTest, CreateSimpleLayout1) {
  auto layout = gs::backend::Layout::GetSimpleLayout(1);
  EXPECT_EQ(layout->layout_items_.size(), 2);
  EXPECT_EQ(layout->total_size_, 5);
  layout->Dump();
  EXPECT_STREQ(gs::logger::last_log.c_str(), "[Layout] a_Position(3) v_texCoord0(2) ");
}

TEST(ParameterTest, CreateSimpleLayout2) {
  auto layout = gs::backend::Layout::GetSimpleLayout(2);
  EXPECT_EQ(layout->layout_items_.size(), 3);
  EXPECT_EQ(layout->total_size_, 7);
  layout->Dump();
  EXPECT_STREQ(gs::logger::last_log.c_str(), "[Layout] a_Position(3) v_texCoord0(2) v_texCoord1(2) ");
}

TEST(ParameterTest, FindUniformLocation) {
  auto program = std::make_shared<gs::backend::Program>(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  program->active();
  EXPECT_GE(program->GetUniformLocation(TEST_UNIFORM), 0);
  EXPECT_GE(program->GetUniformLocation(TEST_UNIFORM2), 0);
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}

TEST(ParameterTest, FindAttributeLocation) {
  auto program = std::make_shared<gs::backend::Program>(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  program->active();
  EXPECT_GE(program->GetAttributeLocation(TEST_ATTRIBUTE), 0);
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}

TEST(ParameterTest, BindIndexParameter) {
  std::vector<uint32_t> index = TEST_INDEX_BUFFER;
  auto index_ptr = std::make_shared<std::vector<uint32_t>>(std::move(index));
  auto index_parameter = std::make_shared<gs::backend::IndexParameter>(index_ptr);
  EXPECT_FALSE(gs::glchecker::has_gl_error);
  auto program = std::make_shared<gs::backend::Program>(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  program->active();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
  index_parameter->Bind(program);
  EXPECT_FALSE(gs::glchecker::has_gl_error);
  index_parameter->Unbind(program);
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}

TEST(ParameterTest, BindVertexParameter) {
  std::vector<float> vertex = TEST_VERTEX_BUFFER;
  auto vertex_ptr = std::make_shared<std::vector<float>>(std::move(vertex));
  auto layout = gs::backend::Layout::GetSimpleLayout(0);
  auto vertex_parameter = std::make_shared<gs::backend::VertexParameter>(vertex_ptr, layout);
  EXPECT_FALSE(gs::glchecker::has_gl_error);
  auto program = std::make_shared<gs::backend::Program>(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  program->active();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
  vertex_parameter->Bind(program);
  EXPECT_FALSE(gs::glchecker::has_gl_error);
  vertex_parameter->Unbind(program);
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}
