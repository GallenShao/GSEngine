/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * vertex_buffer.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "vertex_buffer.h"

#include <sstream>

#include "utils/gs_logger.h"

#define TAG "VertexBuffer"

namespace gs::backend {

VertexBuffer::VertexBuffer(const std::shared_ptr<std::vector<float>>& data)
    : Buffer(BufferType::ARRAY_BUFFER, data->data(), data->size(), sizeof(float)), data_(data) {}

void VertexBuffer::Dump() {
  std::stringstream ss;
  auto& data = *data_;
  if (item_counts_ > 1) {
    ss << data[0];
  }
  for (int i = 1; i < item_counts_; i++) {
    ss << ", " << data[i];
  }
  LOG(LEVEL_INFO, TAG) << "[" << id_ << "] " << ss.str();
}

}  // namespace gs::backend
