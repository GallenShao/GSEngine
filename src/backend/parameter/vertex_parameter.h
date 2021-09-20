/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * VertexParameter.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include "buffer/vertex_buffer.h"
#include "layout.h"
#include "parameter.h"

namespace gs::backend {

class VertexParameter : public Parameter {
 public:
  VertexParameter(const std::shared_ptr<std::vector<float>>& indices_ptr, const std::shared_ptr<Layout>& layout);

  ~VertexParameter();

  void Bind(const std::shared_ptr<Program>& program) override;

  void Unbind(const std::shared_ptr<Program>& program) override;

 private:
  std::shared_ptr<VertexBuffer> vertex_buffer_;
  std::shared_ptr<Layout> layout_;
};

}  // namespace gs::backend
