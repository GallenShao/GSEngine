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

namespace gs::backend {

Program::Program(const char* vertex_shader, const char* fragment_shader) {
  v_shader_ = std::make_shared<Shader>(Vertex, vertex_shader);
  f_shader_ = std::make_shared<Shader>(Fragment, fragment_shader);

  GS_GL_CHECKER(id_ = glCreateProgram())
  if (id_ == 0) {
    LOG(LEVEL_ERROR, TAG) << "fail to create program";
    return;
  }
  LOG(LEVEL_INFO, TAG) << "program created[" << id_ << "].";

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

uint64_t Program::GetId() const { return id_; }

void Program::active() const {
  if (id_ == 0) return;
  GS_GL_CHECKER(glUseProgram(id_))
}

void Program::inactive() { GS_GL_CHECKER(glUseProgram(0)) }

void Program::destroy() {
  if (id_ == 0) return;

  GS_GL_CHECKER(glDeleteProgram(id_))
  LOG(LEVEL_INFO, TAG) << "program deleted[" << id_ << "].";
  id_ = 0;
}

int32_t Program::GetUniformLocation(const std::string& key) {
  if (id_ == 0) return -1;

  auto iter = location_map_.find(key);
  if (iter != location_map_.end()) {
    return iter->second;
  }

  int32_t location = -1;
  GS_GL_CHECKER(location = glGetUniformLocation(id_, key.c_str()))
  if (location < 0) {
    LOG(LEVEL_WARN, TAG) << "could not found uniform [" << key << "] in program [" << id_ << "].";
    return -1;
  }
  LOG(LEVEL_INFO, TAG) << "location of [" << key << "] is " << location;

  location_map_[key] = location;
  return location;
}

int32_t Program::GetAttributeLocation(const std::string& key) {
  if (id_ == 0) return -1;

  auto iter = location_map_.find(key);
  if (iter != location_map_.end()) {
    return iter->second;
  }

  int32_t location = -1;
  GS_GL_CHECKER(location = glGetAttribLocation(id_, key.c_str()))
  if (location < 0) {
    LOG(LEVEL_WARN, TAG) << "could not found attribute [" << key << "] in program [" << id_ << "].";
    return -1;
  }
  LOG(LEVEL_INFO, TAG) << "location of [" << key << "] is " << location;

  location_map_[key] = location;
  return location;
}

}  // namespace gs::backend
