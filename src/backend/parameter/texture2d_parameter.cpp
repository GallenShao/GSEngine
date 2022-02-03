/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * texture2d_parameter.cpp
 *
 *  Created on: 2022.2.3
 *  Author: gallenshao
 */

#include "texture2d_parameter.h"

#include "utils/gs_gl_checker.h"

namespace gs::backend {

Texture2DParameter::Texture2DParameter(const std::string& key, const std::shared_ptr<Texture>& texture)
  : UniformParameter(key), texture_(texture) {}

void Texture2DParameter::UpdateValue(const std::shared_ptr<Texture>& texture) {
  texture_ = texture;
}

void Texture2DParameter::Dobind(std::shared_ptr<Program>& program) {
  GS_GL_CHECKER(glUniform1i(location_, program->texture_count_))
  GS_GL_CHECKER(glActiveTexture(GL_TEXTURE0 + program->texture_count_))
  texture_->active();
  program->texture_count_++;
}

void Texture2DParameter::Unbind(std::shared_ptr<Program>& program) {}

}  // namespace gs::backend
