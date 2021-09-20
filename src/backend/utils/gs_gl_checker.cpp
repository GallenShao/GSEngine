/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * gs_gl_checker.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "gs_gl_checker.h"

namespace gs::glchecker {

const char* gl_error_msg[] = {"GL_INVALID_ENUM",
                              "GL_INVALID_VALUE",
                              "GL_INVALID_OPERATION",
                              "GL_STACK_OVERFLOW",
                              "GL_STACK_UNDERFLOW",
                              "GL_OUT_OF_MEMORY",
                              "GL_INVALID_FRAMEBUFFER_OPERATION"};

}
