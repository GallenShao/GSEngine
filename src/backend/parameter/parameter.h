/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * parameter.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include "program/program.h"

namespace gs::backend {

class Parameter {
 public:
  virtual void Bind(const std::shared_ptr<Program>& program) = 0;

  virtual void Unbind(const std::shared_ptr<Program>& program) = 0;
};

}  // namespace gs::backend
