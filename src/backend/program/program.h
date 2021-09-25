/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * program.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include <cstdint>
#include <memory>
#include <unordered_map>

#include "shader.h"

namespace gs::backend {

class ProgramManager;

class Program {
 public:
  ~Program();

  uint64_t GetId() const;

  bool IsValid() const;

  void active() const;
  static void inactive();

  int32_t GetUniformLocation(const std::string& key);
  int32_t GetAttributeLocation(const std::string& key);

 private:
  uint64_t id_;
  std::shared_ptr<Shader> v_shader_, f_shader_;

  std::unordered_map<std::string, int32_t> location_map_;

  Program(const char* vertex_shader, const char* fragment_shader);
  void destroy();

 friend class ProgramManager;
};

}  // namespace gs::backend
