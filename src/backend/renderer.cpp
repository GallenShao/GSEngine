/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * renderer.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "renderer.h"
#include "parameter/vec4_parameter.h"
#include "parameter/float_parameter.h"
#include "program/program_manager.h"
#include "utils/gs_gl_checker.h"

namespace gs::backend {

Renderer::Renderer(const char* vertex_shader, const char* fragment_shader, DrawMode draw_mode) : draw_mode_(draw_mode) {
  program_ = ProgramManager::GetInstance()->Get(vertex_shader, fragment_shader);
}

void Renderer::SetParameter(const std::string& key, const std::shared_ptr<Parameter>& parameter) {
  parameters_[key] = parameter;
}

void Renderer::SetVertices(const std::shared_ptr<VertexParameter>& vertex_parameter) {
  SetParameter(DEFAULT_VERTEX_PARAMETER_KEY, vertex_parameter);
}

void Renderer::SetIndices(const std::shared_ptr<IndexParameter>& index_parameter) {
  index_parameter_ = index_parameter;
  SetParameter(DEFAULT_INDEX_PARAMETER_KEY, index_parameter);
}

void Renderer::SetUniforms(const std::string& key, float x) {
  auto iter = parameters_.find(key);
  if (iter != parameters_.end()) {
    std::static_pointer_cast<FloatParameter>(iter->second)->UpdateValue(x);
    return;
  }

  auto uniform_parameter = std::make_shared<FloatParameter>(key, x);
  SetParameter(key, uniform_parameter);
}

void Renderer::SetUniforms(const std::string& key, float x, float y, float z, float w) {
  auto iter = parameters_.find(key);
  if (iter != parameters_.end()) {
    std::static_pointer_cast<Vec4Parameter>(iter->second)->UpdateValue(x, y, z, w);
    return;
  }

  auto uniform_parameter = std::make_shared<Vec4Parameter>(key, x, y, z, w);
  SetParameter(key, uniform_parameter);
}

void Renderer::Render() {
  if (program_ == nullptr || !program_->IsValid()) return;

  program_->active();
  BindRenderState();
  BindParameters();
  PerformRender();
  UnbindParameters();
  program_->inactive();
}

void Renderer::BindRenderState() {
  GS_GL_CHECKER(glEnable(GL_BLEND))
  GS_GL_CHECKER(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA))
}

void Renderer::BindParameters() {
  for (auto& parameter : parameters_) {
    parameter.second->Bind(program_);
  }
}

void Renderer::PerformRender() {
  int mode;
  switch (draw_mode_) {
    case GS_LINES:
      mode = GL_LINES;
      break;
    case GS_TRIANGLES:
    default:
      mode = GL_TRIANGLES;
      break;
  }

  GS_GL_CHECKER(glDrawElements(mode, index_parameter_->GetElementSize(), GL_UNSIGNED_INT, 0))
}

void Renderer::UnbindParameters() {
  for (auto& parameter : parameters_) {
    parameter.second->Unbind(program_);
  }
}

}  // namespace gs::backend