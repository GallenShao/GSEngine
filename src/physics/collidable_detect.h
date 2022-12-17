/**
 * Copyright 2022 by GallenShao, All Rights Reserved.
 *
 * collidable_detect.h
 *
 *  Created on: 2022.2.5
 *  Author: gallenshao
 */

#include "collidable.h"

namespace gs::physics
{

class CollidableDetect {
 public:

// ========== Roughly Detect ==========

  static bool WillCollide(Collidable* obj1, Collidable* obj2);

// ========== Fine Tuned ==========



};

} // namespace gs::physics
