/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * texture2d_parameter.h
 *
 *  Created on: 2022.2.3
 *  Author: gallenshao
 */

#pragma once

#include "uniform_parameter.h"
#include "resource/texture.h"

namespace gs::backend {

class Texture2DParameter : public UniformParameter {
 public:
  Texture2DParameter(const std::string& key, const std::shared_ptr<Texture>& texture);
  void Dobind(std::shared_ptr<Program>& program) override;
  void Unbind(std::shared_ptr<Program>& program) override;

  void UpdateValue(const std::shared_ptr<Texture>& texture);

 private:
  std::shared_ptr<Texture> texture_;
};

}  // namespace gs::backend
