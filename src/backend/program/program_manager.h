/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * program_manager.h
 *
 *  Created on: 2021.09.25
 *  Author: gallenshao
 */

#pragma once

#include <memory>
#include <unordered_map>

#include "program.h"

namespace gs::backend {

class ProgramManager {
 public:
  static std::shared_ptr<ProgramManager> GetInstance();

  std::shared_ptr<Program> Get(const char* vertex_shader, const char* fragment_shader);

 private:
  std::size_t GetHash(const char* vertex_shader, const char* fragment_shader);

  static std::shared_ptr<ProgramManager> program_manager_;
  std::unordered_map<std::size_t, std::shared_ptr<Program>> program_pool;
};


}  // namespace gs::backend
