/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * renderer.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include "parameter/vertex_parameter.h"
#include "parameter/index_parameter.h"
#include "program/program.h"

#include <unordered_map>

namespace gs::backend {

#define DEFAULT_VERTEX_PARAMETER_KEY "vertex"
#define DEFAULT_INDEX_PARAMETER_KEY "index"

enum DrawMode {
  GS_TRIANGLES = 0,
  GS_LINES = 1
};

class Renderer {
 public:
  Renderer(const char* vertex_shader, const char* fragment_shader, DrawMode draw_mode = GS_TRIANGLES);

  void Render();

  void SetParameter(const std::string& key, const std::shared_ptr<Parameter>& parameter);
  void SetVertices(const std::shared_ptr<VertexParameter>& index_parameter);
  void SetIndices(const std::shared_ptr<IndexParameter>& index_parameter);

  void SetUniforms(const std::string& key, float x);
  void SetUniforms(const std::string& key, float x, float y, float z, float w);

 private:
  std::shared_ptr<Program> program_;
  std::unordered_map<std::string, std::shared_ptr<Parameter>> parameters_;
  std::shared_ptr<IndexParameter> index_parameter_;
  DrawMode draw_mode_;

  void BindRenderState();
  void BindParameters();
  void PerformRender();
  void UnbindParameters();
};

}
