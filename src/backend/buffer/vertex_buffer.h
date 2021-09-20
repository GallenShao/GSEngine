/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * vertex_buffer.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include <vector>

#include "buffer.h"

namespace gs::backend {

class VertexBuffer : public Buffer {
 public:
  explicit VertexBuffer(const std::shared_ptr<std::vector<float>>& data);

 private:
  std::shared_ptr<std::vector<float>> data_;
};

}  // namespace gs
