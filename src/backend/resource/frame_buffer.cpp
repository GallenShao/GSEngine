/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * frame_buffer.cpp
 *
 *  Created on: 2021.09.21
 *  Author: gallenshao
 */

#include "frame_buffer.h"
#include "utils/gs_gl_checker.h"

namespace gs::backend {

FrameBuffer::FrameBuffer() {

}

FrameBuffer::~FrameBuffer() {
  ReleaseFrameBuffer();
}

void FrameBuffer::GenFrameBuffer() {
  GS_GL_CHECKER(glGenFramebuffers(1, &id_))
}

void FrameBuffer::ReleaseFrameBuffer() {
  if (id_ != 0) {
    if (!is_external_) {
      GS_GL_CHECKER(glDeleteFramebuffers(1, &id_))
    }
    id_ = 0;
  }
  width_ = 0;
  height_ = 0;
  is_external_ = false;
}

/**
 * make FrameBuffer instance from external frame buffer id
 */
std::shared_ptr<FrameBuffer> FrameBuffer::FromExternal(int frame_buffer_id, int width, int height) {
  auto fb = std::make_shared<FrameBuffer>();
  fb->is_external_ = true;
  fb->id_ = frame_buffer_id;
  fb->width_ = width;
  fb->height_ = height;
  return fb;
}

/**
 * make blank FrameBuffer instance
 */
std::shared_ptr<FrameBuffer> FrameBuffer::FromBlank() {
  auto fb = std::make_shared<FrameBuffer>();
  fb->GenFrameBuffer();
  return fb;
}

/**
 * make FrameBuffer instance from size
 */
std::shared_ptr<FrameBuffer> FrameBuffer::FromSize(int width, int height) {
  auto texture = Texture::FromSize(width, height);
  return FrameBuffer::FromTexture(texture);
}

/**
 * make FrameBuffer instance from texture
 */
std::shared_ptr<FrameBuffer> FrameBuffer::FromTexture(int texture_id, int width, int height) {
  auto texture = Texture::FromExternal(texture_id, width, height);
  return FrameBuffer::FromTexture(texture);
}

/**
 * make FrameBuffer instance from texture
 */
std::shared_ptr<FrameBuffer> FrameBuffer::FromTexture(const std::shared_ptr<gs::backend::Texture>& texture) {
  auto fb = FromBlank();
  fb->active();
  fb->BindColorAttachment(texture);
  fb->inactive();
  return fb;
}

void FrameBuffer::BindColorAttachment(const std::shared_ptr<gs::backend::Texture>& texture) {
  if (texture == nullptr) {
    GS_GL_CHECKER(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, 0, 0));
    color_attachment_ = nullptr;
    width_ = 0;
    height_ = 0;
    return;
  }

  GS_GL_CHECKER(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture->GetId(), 0));
  color_attachment_ = texture;
  width_ = texture->GetWidth();
  height_ = texture->GetHeight();
}

void FrameBuffer::active() {
  GS_GL_CHECKER(glBindFramebuffer(GL_FRAMEBUFFER, id_))
}

void FrameBuffer::inactive() {
  GS_GL_CHECKER(glBindFramebuffer(GL_FRAMEBUFFER, 0))
}

uint32_t FrameBuffer::GetId() {
  return id_;
}

int FrameBuffer::GetWidth() {
  return width_;
}

int FrameBuffer::GetHeight() {
  return height_;
}

std::shared_ptr<gs::backend::Texture> FrameBuffer::GetColorAttachment() {
  return color_attachment_;
}

} // namespace gs::backend