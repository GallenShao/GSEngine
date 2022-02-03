/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_program.cpp
 *
 *  Created on: 2022.2.3
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include "resource/texture.h"
#include "test_constants.h"
#include "utils/gs_gl_checker.h"

TEST(TextureTest, CreateTexture) {
  auto texture = gs::backend::Texture::FromSize(TEST_WIDTH, TEST_HEIGHT);
  EXPECT_NE(texture->GetId(), 0);
  texture->active();
  texture->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}

TEST(TextureTest, CheckExternalTexture) {
  auto external_texture = gs::backend::Texture::FromSize(TEST_WIDTH, TEST_HEIGHT);
  EXPECT_NE(external_texture->GetId(), 0);
  // Try make from external
  auto texture = gs::backend::Texture::FromExternal(external_texture->GetId(), external_texture->GetWidth(), external_texture->GetHeight());
  EXPECT_NE(texture->GetId(), 0);
  texture = nullptr;
  // Check if origin texture is still valid
  external_texture->active();
  external_texture->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}
