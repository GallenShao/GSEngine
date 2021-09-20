/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * gs_gl_checker.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include "GL/glew.h"
#include "gs_logger.h"

#define GS_GL_DEBUG 1

#define GS_GL_TAG "GS_GL"

namespace gs::glchecker {

#if GS_GL_DEBUG
const char* gl_error_msg[] = {"GL_INVALID_ENUM",
                              "GL_INVALID_VALUE",
                              "GL_INVALID_OPERATION",
                              "GL_STACK_OVERFLOW",
                              "GL_STACK_UNDERFLOW",
                              "GL_OUT_OF_MEMORY",
                              "GL_INVALID_FRAMEBUFFER_OPERATION"};

#define GS_GL_CHECKER(func)                                                                            \
  {                                                                                                    \
    func;                                                                                              \
    auto error_code = glGetError();                                                                    \
    if (error_code != 0) {                                                                             \
      LOG(ERROR, GS_GL_TAG) << gl_error_msg[error_code - GL_INVALID_ENUM] << " found after  " << #func \
    }                                                                                                  \
  }
#else
#define GS_GL_CHECKER(func) \
  { func; }
#endif

}  // namespace gs::glchecker
