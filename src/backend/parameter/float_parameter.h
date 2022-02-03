/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * float_parameter.h
 *
 *  Created on: 2021.09.21
 *  Author: gallenshao
 */

#pragma once

#include "uniform_parameter.h"

namespace gs::backend {

class FloatParameter : public UniformParameter {
 public:
  FloatParameter(const std::string& key, float value);
  void Dobind(std::shared_ptr<Program>& program) override;
  void Unbind(std::shared_ptr<Program>& program) override;

  void UpdateValue(float value);

 private:
  float value_;
};

}  // namespace gs::backend
