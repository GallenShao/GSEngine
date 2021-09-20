/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * buffer.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include <cstdint>
#include <memory>

namespace gs::backend {

enum BufferType {
  ARRAY_BUFFER,
  ELEMENT_ARRAY_BUFFER
};

class Buffer {
 public:
  Buffer(BufferType type, const void* data, int item_counts, size_t item_size);
  ~Buffer();

  void active() const;
  void inactive() const;

  uint64_t GetId() const;

 private:
  uint64_t id_ = 0;
  BufferType type_;
  int gl_type_;
  size_t item_size_;
  int item_counts_;
};

}  // namespace gs
