/**
 * Copyright 2022 by GallenShao, All Rights Reserved.
 *
 * math.h
 *
 *  Created on: 2022.2.5
 *  Author: gallenshao
 */

#include <cstdint>

namespace gs::physics
{

typedef uint64_t Time;

class Point {
 public:
  double x;
  double y;
  double z;
};

class Vector {
 public:
  double x;
  double y;
  double z;
};

} // namespace gs::physics
