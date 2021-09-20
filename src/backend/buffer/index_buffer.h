/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * index_buffer.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include <vector>

#include "buffer.h"

namespace gs::backend {

class IndexBuffer : public Buffer {
 public:
  explicit IndexBuffer(const std::shared_ptr<std::vector<uint32_t>>& data);

  void Dump() override;

 private:
  std::shared_ptr<std::vector<uint32_t>> data_;
};

}  // namespace gs
