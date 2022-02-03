/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * texture.cpp
 *
 *  Created on: 2021.09.21
 *  Author: gallenshao
 */

#include "texture.h"
#include "utils/gs_gl_checker.h"

namespace gs::backend {

/**
 * make texture instance from external texture id
 */
std::shared_ptr<Texture> Texture::FromExternal(int texture_id, int width, int height) {
  auto texture = std::make_shared<Texture>();
  texture->is_external_ = true;
  texture->id_ = texture_id;
  texture->width_ = width;
  texture->height_ = height;
  return texture;
}

/**
 * make texture instance from size
 */
std::shared_ptr<Texture> Texture::FromSize(int width, int height) {
  auto texture = std::make_shared<Texture>();
  texture->GenTexture();
  texture->width_ = width;
  texture->height_ = height;
  texture->active();
  // TODO Support texture format/filter
  GS_GL_CHECKER(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL))
  GS_GL_CHECKER(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR))
  GS_GL_CHECKER(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR))
  texture->inactive();
  return texture;
}

Texture::Texture() {

}

Texture::~Texture() {
  ReleaseTexture();
}

void Texture::GenTexture() {
  GS_GL_CHECKER(glGenTextures(1, &id_))
}

void Texture::ReleaseTexture() {
  if (id_ != 0) {
    if (!is_external_) {
      GS_GL_CHECKER(glDeleteTextures(1, &id_))
    }
    id_ = 0;
  }
  width_ = 0;
  height_ = 0;
  is_external_ = false;
}

void Texture::active() {
  GS_GL_CHECKER(glBindTexture(GL_TEXTURE_2D, id_))
}

void Texture::inactive() {
  GS_GL_CHECKER(glBindTexture(GL_TEXTURE_2D, 0))
}

uint32_t Texture::GetId() {
  return id_;
}

int Texture::GetWidth() {
  return width_;
}

int Texture::GetHeight() {
  return height_;
}

} // namespace gs::backend
