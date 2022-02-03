/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * vec4_parameter.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "vec4_parameter.h"

#include "utils/gs_gl_checker.h"

namespace gs::backend {

Vec4Parameter::Vec4Parameter(const std::string& key, float x, float y, float z, float w)
    : UniformParameter(key), x_(x), y_(y), z_(z), w_(w) {}

void Vec4Parameter::UpdateValue(float x, float y, float z, float w) {
  x_ = x;
  y_ = y;
  z_ = z;
  w_ = w;
}

void Vec4Parameter::Dobind(std::shared_ptr<Program>& program) {
  GS_GL_CHECKER(glUniform4f(location_, x_, y_, z_, w_))
}

void Vec4Parameter::Unbind(std::shared_ptr<Program>& program) {}

}  // namespace gs::backend
