/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * vec4_parameter.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include "uniform_parameter.h"

namespace gs::backend {

class Vec4Parameter : public UniformParameter {
 public:
  Vec4Parameter(const std::string& key, float x, float y, float z, float w);
  void Dobind(const std::shared_ptr<Program>& program) override;
  void Unbind(const std::shared_ptr<Program>& program) override;

  void UpdateValue(float x, float y, float z, float w);

 private:
  float x_, y_, z_, w_;
};

}  // namespace gs::backend
