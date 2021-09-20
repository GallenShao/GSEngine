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

#include "parameter/layout.h"
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
