/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * uniform_parameter.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include "parameter.h"

namespace gs::backend {

class UniformParameter : public Parameter {
 public:
  explicit UniformParameter(const std::string& key);

  void Bind(std::shared_ptr<Program>& program) override;

  virtual void Dobind(std::shared_ptr<Program>& program) = 0;

 protected:
  std::string key_;
  int32_t location_ = -1;

 private:
  void GetLocation(const std::shared_ptr<Program>& program);
};

}  // namespace gs::backend
