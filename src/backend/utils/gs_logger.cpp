/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * gs_logger.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "gs_logger.h"

#include <cstdio>

#include "gs_platform.h"

namespace gs::logger {

Logger::Logger(const char *file, int line, int level) : level_(level) {
  stream_ << "[" << file << ":" << line << "] ";
#if GS_MACOS
  switch (level_) {
    case LEVEL_ERROR:
      stream_ << "\033[1;31m";
      break;
    case LEVEL_WARN:
      stream_ << "\033[1;33m";
      break;
    case LEVEL_INFO:
      stream_ << "\033[0m";
      break;
    case LEVEL_DEBUG:
      stream_ << "\033[37m";
      break;
    case LEVEL_VERBOSE:
      stream_ << "\033[1;30m";
      break;
    default:
      break;
  }
#endif
  beginning = stream_.str();
  std::stringstream().swap(stream_);
}

Logger::~Logger() {
  last_log = stream_.str();
#if GS_MACOS
  printf("%s%s\033[0m\n", beginning.c_str(), last_log.c_str());
#endif
}

int min_log_level = LEVEL_INFO;

std::string last_log = "";

void SetMinLogLevel(int level) { min_log_level = level; }

}  // namespace gs::logger
