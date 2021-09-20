/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_constants.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#define TEST_VERTEX_SHADER       \
"attribute vec4 a_Position;    \n\
void main() {                  \n\
  gl_Position = a_Position;    \n\
}"

#define TEST_FRAGMENT_SHADER \
"uniform vec4 u_Color;      \n\
void main() {              \n\
  gl_FragColor = u_Color;  \n\
}"