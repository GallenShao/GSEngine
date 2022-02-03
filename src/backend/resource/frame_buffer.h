/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * frame_buffer.h
 *
 *  Created on: 2021.09.21
 *  Author: gallenshao
 */

#pragma once

#include "texture.h"
#include <memory>

namespace gs::backend {

class FrameBuffer {
 public:
  FrameBuffer();
  ~FrameBuffer();
  /**
   * make FrameBuffer instance from external frame buffer id
   */
  static std::shared_ptr<FrameBuffer> FromExternal(int frame_buffer_id, int width, int height);
  /**
   * make blank FrameBuffer instance
   */
  static std::shared_ptr<FrameBuffer> FromBlank();
  /**
   * make FrameBuffer instance from size
   */
  static std::shared_ptr<FrameBuffer> FromSize(int width, int height);
  /**
   * make FrameBuffer instance from texture
   */
  static std::shared_ptr<FrameBuffer> FromTexture(int texture_id, int width, int height);
  /**
   * make FrameBuffer instance from texture
   */
  static std::shared_ptr<FrameBuffer> FromTexture(const std::shared_ptr<gs::backend::Texture>& texture);

  void BindColorAttachment(const std::shared_ptr<gs::backend::Texture>& texture);

  void active();
  void inactive();

  uint32_t GetId();
  int GetWidth();
  int GetHeight();
  std::shared_ptr<gs::backend::Texture> GetColorAttachment();

 private:
  void GenFrameBuffer();
  void ReleaseFrameBuffer();

  bool is_external_ = false;
  uint32_t id_ = 0;
  int width_ = 0;
  int height_ = 0;
  std::shared_ptr<gs::backend::Texture> color_attachment_ = nullptr;
};

} // namespace gs::backend
