/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * gs_gl_checker.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include "OpenGL/gl.h"
#include "gs_logger.h"

#define GS_GL_CHECKER_ENABLED 1
#define GS_GL_CHECKER_VERBOSE 0

#define GS_GL_TAG "GS_GL_CHECKER"

namespace gs::glchecker {

#if GS_GL_CHECKER_VERBOSE
#define GS_GL_TRACE(func) LOG(LEVEL_DEBUG, GS_GL_TAG) << #func;
#else
#define GS_GL_TRACE(func)
#endif

#if GS_GL_CHECKER_ENABLED
extern const char* gl_error_msg[];

#define GS_GL_CHECKER(func)                                                                                       \
  {                                                                                                               \
    GS_GL_TRACE(func);                                                                                            \
    func;                                                                                                         \
    auto error_code = glGetError();                                                                               \
    if (error_code != 0) {                                                                                        \
      LOG(LEVEL_ERROR, GS_GL_TAG) << gs::glchecker::gl_error_msg[error_code - GL_INVALID_ENUM] << " found after " \
                                  << #func;                                                                       \
    }                                                                                                             \
  }
#else
#define GS_GL_CHECKER(func) \
  { func; }
#endif

}  // namespace gs::glchecker
