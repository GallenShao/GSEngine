/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * index_buffer.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "index_buffer.h"

#include <sstream>

#include "utils/gs_logger.h"

#define TAG "IndexBuffer"

namespace gs::backend {

IndexBuffer::IndexBuffer(const std::shared_ptr<std::vector<uint32_t>>& data)
    : Buffer(BufferType::ELEMENT_ARRAY_BUFFER, data->data(), data->size(), sizeof(uint32_t)), data_(data) {}

void IndexBuffer::Dump() {
  std::stringstream ss;
  auto& data = *data_;
  if (item_counts_ > 1) {
    ss << data[0];
  }
  for (int i = 1; i < item_counts_; i++) {
    ss << ", " << data[i];
  }
  LOG(LEVEL_DEBUG, TAG) << "[" << id_ << "] " << ss.str();
}

size_t IndexBuffer::GetElementSize() {
  return data_->size();
}

}  // namespace gs::backend