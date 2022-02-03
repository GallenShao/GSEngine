/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * texture.h
 *
 *  Created on: 2021.09.21
 *  Author: gallenshao
 */

#pragma once

#include <memory>

namespace gs::backend {

class Texture {
 public:
  Texture();
  ~Texture();
  /**
   * make texture instance from external texture id
   */
  static std::shared_ptr<Texture> FromExternal(int texture_id, int width, int height);
  /**
   * make texture instance from size
   */
  static std::shared_ptr<Texture> FromSize(int width, int height);

  void active();
  void inactive();

  uint32_t GetId();
  int GetWidth();
  int GetHeight();

 private:
  void GenTexture();
  void ReleaseTexture();

  bool is_external_ = false;
  uint32_t id_ = 0;
  int width_ = 0;
  int height_ = 0;
};

} // namespace gs::backend
