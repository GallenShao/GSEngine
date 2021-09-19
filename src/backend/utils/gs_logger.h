/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * gs_logger.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#define LEVEL_ERROR 5
#define LEVEL_WARN 4
#define LEVEL_INFO 3
#define LEVEL_DEBUG 2
#define LEVEL_VERBOSE 1

#include <sstream>

namespace gs::logger {

extern int min_log_level;

// This class is used to explicitly ignore values in the conditional
// logging macros. This avoids compiler warnings like "value computed
// is not used" and "statement has no effect".
class LoggerVoidify {
 public:
  LoggerVoidify() = default;
  // This has to be an operator with a precedence lower than << but
  // higher than ?:
  void operator&(const std::ostream &s) {}
};

class Logger {
 public:
  Logger(const char *file, int line, int level);

  ~Logger();

  std::stringstream &stream() { return stream_; }

 private:
  std::stringstream stream_;
  int level_;
};

void SetMinLogLevel(int level);

#define LOG(LEVEL)                  \
  LEVEL < gs::logger::min_log_level \
      ? (void)0                     \
      : gs::logger::LoggerVoidify() & gs::logger::Logger(__FILE__, __LINE__, LEVEL).stream()

}  // namespace gs::logger
