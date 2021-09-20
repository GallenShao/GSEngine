/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_program.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include "program.h"
#include "test_constants.h"

TEST(ProgramTest, CreateProgram) {
  auto program = new gs::Program(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  EXPECT_NE(program->GetId(), 0);
  delete program;
}
