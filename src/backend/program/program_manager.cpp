/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * program_manager.cpp
 *
 *  Created on: 2021.09.25
 *  Author: gallenshao
 */

#include "program_manager.h"
#include "utils/hash_utils.h"

namespace gs::backend {

std::shared_ptr<ProgramManager> ProgramManager::program_manager_ = nullptr;

std::shared_ptr<ProgramManager> ProgramManager::GetInstance() {
	if (program_manager_ == nullptr) {
		program_manager_ = std::make_shared<ProgramManager>();
	}
	return program_manager_;
}

std::shared_ptr<Program> ProgramManager::Get(const char* vertex_shader, const char* fragment_shader) {
  auto hash = GetHash(vertex_shader, fragment_shader);
  auto iter = program_pool.find(hash);
  if (iter != program_pool.end()) {
    return iter->second;
  }

  auto program = std::shared_ptr<Program>(new Program(vertex_shader, fragment_shader));
  program_pool[hash] = program;
  return program;
}

std::size_t ProgramManager::GetHash(const char* vertex_shader, const char* fragment_shader) {
  return HashUtils::GetHash(vertex_shader, fragment_shader);
}

}  // namespace gs::backend
