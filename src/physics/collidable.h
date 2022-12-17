/**
 * Copyright 2022 by GallenShao, All Rights Reserved.
 *
 * collidable.h
 *
 *  Created on: 2022.2.5
 *  Author: gallenshao
 */

#include "math.h"

namespace gs::physics
{

class Collidable {
 public:

// ========== Roughly Detect ==========

  virtual Point GetCenter() = 0;

  virtual double GetMaxRadius() = 0;

// ========== Fine Tuned ==========



};

} // namespace gs::physics
