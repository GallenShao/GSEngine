/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * program.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "program.h"

#include "utils/gs_gl_checker.h"

#define TAG "Program"

namespace gs {

Program::Program(const char *vertex_shader, const char *fragment_shader) {
  v_shader_ = std::make_shared<Shader>(Vertex, vertex_shader);
  f_shader_ = std::make_shared<Shader>(Fragment, fragment_shader);

  id_ = glCreateProgram();
  if (id_ == 0) {
    LOG(LEVEL_ERROR, TAG) << "fail to create program";
    return;
  }
  LOG(LEVEL_INFO, TAG) << "create program [" << id_ << "]";

  GS_GL_CHECKER(glAttachShader(id_, v_shader_->GetId()))
  GS_GL_CHECKER(glAttachShader(id_, f_shader_->GetId()))
  GS_GL_CHECKER(glLinkProgram(id_))

  int link_status;
  GS_GL_CHECKER(glGetProgramiv(id_, GL_LINK_STATUS, &link_status))
  if (link_status == 0) {
    int len;
    char log[1024];
    GS_GL_CHECKER(glGetProgramInfoLog(id_, sizeof(log), &len, log))
    LOG(LEVEL_ERROR, TAG) << "fail to link program[" << id_ << "]: " << log;
    destroy();
  }
}

Program::~Program() {
  destroy();
  v_shader_ = nullptr;
  f_shader_ = nullptr;
}

uint64_t Program::GetId() { return id_; }

void Program::active() {
  if (id_ == 0) return;
  GS_GL_CHECKER(glUseProgram(id_))
}

void Program::inactive() {
  GS_GL_CHECKER(glUseProgram(0))
}

void Program::destroy() {
  if (id_ == 0) return;

  GS_GL_CHECKER(glDeleteProgram(id_))
  id_ = 0;
}

}  // namespace gs
