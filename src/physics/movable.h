/**
 * Copyright 2022 by GallenShao, All Rights Reserved.
 *
 * movable.h
 *
 *  Created on: 2022.2.5
 *  Author: gallenshao
 */

#include "math.h"

namespace gs::physics
{

class Movable {
 public:

 private:
  Point position_;
  double velocity_;
  Vector direction_;
};

} // namespace gs::physics
