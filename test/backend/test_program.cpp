/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_program.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include "program/program_manager.h"
#include "test_constants.h"
#include "utils/gs_gl_checker.h"

TEST(ProgramTest, CreateProgram) {
  auto program = gs::backend::ProgramManager::GetInstance()->Get(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  EXPECT_NE(program->GetId(), 0);
  program->active();
  program->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}

TEST(ProgramTest, CheckProgramManager) {
  auto program_1 = gs::backend::ProgramManager::GetInstance()->Get(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  auto program_2 = gs::backend::ProgramManager::GetInstance()->Get(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  EXPECT_NE(program_1->GetId(), 0);
  EXPECT_NE(program_2->GetId(), 0);
  EXPECT_EQ(program_1->GetId(), program_2->GetId());
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}
