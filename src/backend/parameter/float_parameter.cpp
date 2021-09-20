/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * float_parameter.cpp
 *
 *  Created on: 2021.09.21
 *  Author: gallenshao
 */

#include "float_parameter.h"

#include "utils/gs_gl_checker.h"

namespace gs::backend {

FloatParameter::FloatParameter(const std::string& key, float value) : UniformParameter(key), value_(value) {}

void FloatParameter::UpdateValue(float value) { value_ = value; }

void FloatParameter::Dobind(const std::shared_ptr<Program>& program) { GS_GL_CHECKER(glUniform1f(location_, value_)) }

void FloatParameter::Unbind(const std::shared_ptr<Program>& program) {}

}  // namespace gs::backend
