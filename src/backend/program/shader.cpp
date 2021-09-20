/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * shader.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "shader.h"

#include "utils/gs_gl_checker.h"

#define TAG "Shader"

namespace gs::backend {

Shader::Shader(ShaderType type, const char* shader_source) : type_(type) {
  id_ = glCreateShader(GetGLType());
  if (id_ == 0) {
    LOG(LEVEL_ERROR, TAG) << "fail to create " << GetGLTypeStr() << " shader";
    return;
  }
  LOG(LEVEL_INFO, TAG) << GetGLTypeStr() << " shader created[" << id_ << "].";
  GS_GL_CHECKER(glShaderSource(id_, 1, &shader_source, nullptr))
  GS_GL_CHECKER(glCompileShader(id_))

  int compile_status;
  GS_GL_CHECKER(glGetShaderiv(id_, GL_COMPILE_STATUS, &compile_status))
  if (compile_status == 0) {
    int len;
    char log[1024];
    GS_GL_CHECKER(glGetShaderInfoLog(id_, sizeof(log), &len, log))
    LOG(LEVEL_ERROR, TAG) << "fail to compile shader, source:\n" << shader_source << "\nError Info: " << log;
    destroy();
  }
}

Shader::~Shader() { destroy(); }

uint64_t Shader::GetId() const { return id_; }

void Shader::destroy() {
  if (id_ == 0) return;

  GS_GL_CHECKER(glDeleteShader(id_))
  LOG(LEVEL_INFO, TAG) << GetGLTypeStr() << " shader deleted[" << id_ << "].";
  id_ = 0;
}

int Shader::GetGLType() { return type_ == ShaderType::Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER; }

std::string Shader::GetGLTypeStr() { return type_ == ShaderType::Vertex ? "vertex" : "fragment"; }

}  // namespace gs