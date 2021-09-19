/**
 * Copyright 2021 by GallenShao, All Rights Reserved.
 *
 * gs_engine.cpp
 *
 *  Created on: 2021.9.19
 *  Author: gallenshao
 */

#include "gs_engine.h"
#include "backend/utils/gs_logger.h"

gs::GSEngine::GSEngine() {
  logger::SetMinLogLevel(LEVEL_INFO);
  LOG(LEVEL_INFO) << "Make GSEngine";
}
