/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * index_parameter.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include "buffer/index_buffer.h"
#include "parameter.h"

namespace gs::backend {

class IndexParameter : public Parameter {
 public:
  explicit IndexParameter(const std::shared_ptr<std::vector<uint32_t>>& indices_ptr);

  ~IndexParameter();

  void Bind(std::shared_ptr<Program>& program) override;

  void Unbind(std::shared_ptr<Program>& program) override;

  size_t GetElementSize();

 private:
  std::shared_ptr<IndexBuffer> index_buffer_;
};

}  // namespace gs::backend
