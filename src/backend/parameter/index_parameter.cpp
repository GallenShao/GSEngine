/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * index_parameter.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "index_parameter.h"

#include "utils/gs_logger.h"

namespace gs::backend {

IndexParameter::IndexParameter(const std::shared_ptr<std::vector<uint32_t>>& indices_ptr) {
  index_buffer_ = std::make_shared<IndexBuffer>(indices_ptr);
}

IndexParameter::~IndexParameter() { index_buffer_ = nullptr; }

void IndexParameter::Bind(const std::shared_ptr<Program>& program) {
  index_buffer_->active();

  if (gs::logger::NeedLog(LEVEL_DEBUG)) {
    index_buffer_->Dump();
  }
}

void IndexParameter::Unbind(const std::shared_ptr<Program>& program) { index_buffer_->inactive(); }

size_t IndexParameter::GetElementSize() {
  return index_buffer_->GetElementSize();
}

}  // namespace gs::backend