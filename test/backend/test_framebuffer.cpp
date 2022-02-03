/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_program.cpp
 *
 *  Created on: 2022.2.3
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include "resource/frame_buffer.h"
#include "test_constants.h"
#include "utils/gs_gl_checker.h"

void ChechFrameBufferValid(const std::shared_ptr<gs::backend::FrameBuffer> fb) {
  EXPECT_NE(fb->GetId(), 0);
  EXPECT_EQ(fb->GetWidth(), TEST_WIDTH);
  EXPECT_EQ(fb->GetHeight(), TEST_HEIGHT);
  auto texture = fb->GetColorAttachment();
  EXPECT_NE(texture, nullptr);
  EXPECT_NE(texture->GetId(), 0);
  EXPECT_EQ(texture->GetWidth(), TEST_WIDTH);
  EXPECT_EQ(texture->GetHeight(), TEST_HEIGHT);
}

TEST(FrameBufferTest, CreateFromSize) {
  auto fb = gs::backend::FrameBuffer::FromSize(TEST_WIDTH, TEST_HEIGHT);
  ChechFrameBufferValid(fb);
  fb->active();
  fb->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}

TEST(FrameBufferTest, CreateFromExternal) {
  auto external_fb = gs::backend::FrameBuffer::FromSize(TEST_WIDTH, TEST_HEIGHT);
  EXPECT_NE(external_fb->GetId(), 0);
  // Try make from external & release it
  auto fb = gs::backend::FrameBuffer::FromExternal(external_fb->GetId(), external_fb->GetWidth(), external_fb->GetHeight());
  EXPECT_NE(fb->GetId(), 0);
  EXPECT_EQ(fb->GetWidth(), TEST_WIDTH);
  EXPECT_EQ(fb->GetHeight(), TEST_HEIGHT);
  fb = nullptr;
  // Check if origin frame buffer is still valid
  external_fb->active();
  external_fb->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}

TEST(FrameBufferTest, CreateFromExternalTexture1) {
  auto external_texture = gs::backend::Texture::FromSize(TEST_WIDTH, TEST_HEIGHT);
  EXPECT_NE(external_texture->GetId(), 0);
  // Try make from external & release it
  auto fb = gs::backend::FrameBuffer::FromTexture(external_texture->GetId(), external_texture->GetWidth(), external_texture->GetHeight());
  ChechFrameBufferValid(fb);
  fb = nullptr;
  // Check if origin texture is still valid
  external_texture->active();
  external_texture->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}

TEST(FrameBufferTest, CreateFromExternalTexture2) {
  auto external_texture = gs::backend::Texture::FromSize(TEST_WIDTH, TEST_HEIGHT);
  EXPECT_NE(external_texture->GetId(), 0);
  // Try make from external & release it
  auto fb = gs::backend::FrameBuffer::FromTexture(external_texture);
  ChechFrameBufferValid(fb);
  fb = nullptr;
  // Check if origin texture is still valid
  external_texture->active();
  external_texture->inactive();
  EXPECT_FALSE(gs::glchecker::has_gl_error);
}
