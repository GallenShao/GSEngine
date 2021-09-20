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

#define TEST_FRAGMENT_SHADER             \
"uniform vec4 u_color;                 \n\
uniform float u_alpha;                 \n\
void main() {                          \n\
  gl_FragColor = u_color * u_alpha;    \n\
}"

#define TEST_UNIFORM "u_color"
#define TEST_UNIFORM2 "u_alpha"
#define TEST_ATTRIBUTE "a_Position"

#define TEST_VERTEX_BUFFER { 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f, -1.0f, -1.0f, 0.0f, -1.0f, 1.0f, 0.0f }

#define TEST_INDEX_BUFFER { 0, 1, 2, 2, 3, 0 }