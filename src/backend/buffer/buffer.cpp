/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * buffer.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "buffer.h"

#include "utils/gs_gl_checker.h"
#include "utils/gs_logger.h"

#define TAG "Buffer"

namespace gs {

Buffer::Buffer(BufferType type, const void* data, int item_counts, size_t item_size)
    : type_(type), item_counts_(item_counts), item_size_(item_size) {
  gl_type_ = type == BufferType::ARRAY_BUFFER ? GL_ARRAY_BUFFER : GL_ELEMENT_ARRAY_BUFFER;

  GS_GL_CHECKER(glGenBuffers(1, reinterpret_cast<GLuint*>(&id_)))
  if (id_ == 0) {
    LOG(LEVEL_ERROR, TAG) << "fail to gen " << (type_ == BufferType::ARRAY_BUFFER ? "array" : "element array")
                          << " buffer";
    return;
  }
  LOG(LEVEL_INFO, TAG) << (type_ == BufferType::ARRAY_BUFFER ? "array" : "element array") << " buffer created[" << id_
                       << "].";

  GS_GL_CHECKER(glBindBuffer(gl_type_, id_))
  GS_GL_CHECKER(glBufferData(gl_type_, item_counts_ * item_size_, data, GL_DYNAMIC_DRAW))
}

Buffer::~Buffer() {
  if (id_ == 0) return;
  GS_GL_CHECKER(glDeleteBuffers(1, reinterpret_cast<const GLuint*>(&id_)))
  LOG(LEVEL_INFO, TAG) << (type_ == BufferType::ARRAY_BUFFER ? "array" : "element array") << " buffer deleted[" << id_
                       << "].";
}

uint64_t Buffer::GetId() const { return id_; }

void Buffer::active() const {
  if (id_ == 0) return;
  GS_GL_CHECKER(glBindBuffer(gl_type_, id_))
}

void Buffer::inactive() const { GS_GL_CHECKER(glBindBuffer(gl_type_, 0)) }

}  // namespace gs