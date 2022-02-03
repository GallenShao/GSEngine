/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * uniform_parameter.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "uniform_parameter.h"

namespace gs::backend {

UniformParameter::UniformParameter(const std::string& key) : key_(key) {}

void UniformParameter::Bind(std::shared_ptr<Program>& program) {
  if (location_ < 0) {
    GetLocation(program);
  }

  Dobind(program);
}

void UniformParameter::GetLocation(const std::shared_ptr<Program>& program) {
  location_ = program->GetUniformLocation(key_);
}

}  // namespace gs::backend
