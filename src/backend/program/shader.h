/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * shader.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include <cstdint>
#include <string>

namespace gs::backend {

enum ShaderType { Vertex = 0, Fragment = 1 };

class Shader {
 public:
  Shader(ShaderType type, const char* shader_source);
  ~Shader();

  uint64_t GetId() const;

 private:
  ShaderType type_;
  uint64_t id_ = 0;

  void destroy();

  inline int GetGLType();
  inline std::string GetGLTypeStr();
};

}  // namespace gs
