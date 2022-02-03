/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * VertexParameter.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "vertex_parameter.h"

#include "utils/gs_gl_checker.h"
#include "utils/gs_logger.h"

namespace gs::backend {

VertexParameter::VertexParameter(const std::shared_ptr<std::vector<float>>& vertices_ptr,
                                 const std::shared_ptr<Layout>& layout)
    : layout_(layout) {
  vertex_buffer_ = std::make_shared<VertexBuffer>(vertices_ptr);

  if (gs::logger::NeedLog(LEVEL_DEBUG)) {
    vertex_buffer_->Dump();
  }
}

VertexParameter::~VertexParameter() { vertex_buffer_ = nullptr; }

void VertexParameter::Bind(std::shared_ptr<Program>& program) {
  vertex_buffer_->active();
  for (auto& item : layout_->layout_items_) {
    uint32_t location = program->GetAttributeLocation(item.name_);
    GS_GL_CHECKER(glVertexAttribPointer(location, item.size_, GL_FLOAT, false, layout_->total_size_ * sizeof(float),
                                        (const GLvoid*)(item.offset_ * sizeof(float))))
    GS_GL_CHECKER(glEnableVertexAttribArray(location))
  }

  if (gs::logger::NeedLog(LEVEL_DEBUG)) {
    vertex_buffer_->Dump();
  }
}

void VertexParameter::Unbind(std::shared_ptr<Program>& program) { vertex_buffer_->inactive(); }

}  // namespace gs::backend