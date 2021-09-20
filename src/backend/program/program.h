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
#include "shader.h"

namespace gs::backend {

class Program {
 public:
  Program(const char* vertex_shader, const char* fragment_shader);
  ~Program();

  uint64_t GetId() const;

  void active() const;
  static void inactive();

 private:
  uint64_t id_;
  std::shared_ptr<Shader> v_shader_, f_shader_;

  void destroy();
};

}  // namespace gs
