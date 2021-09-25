/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * gs_hasher.h
 *
 *  Created on: 2021.09.25
 *  Author: gallenshao
 */

#pragma once

#include <functional>

namespace gs::backend {

class HashUtils {
 public:
  template <typename T, typename... Rest>
  static std::size_t GetHash(const T& obj, Rest... rest) {
    return CombineHash(0, obj, rest...);
  }
  
  template <typename T>
  static typename std::enable_if<!std::is_same<T, char*>::value, std::size_t>::type GetHash(const T& obj) {
    std::hash<T> hasher;
    return hasher(obj);
  }

  static std::size_t GetHash(const char* obj) {
    return GetHash(std::string(obj));
  }

 private:
  template <typename T, typename... Rest>
  static std::size_t CombineHash(std::size_t seed, const T& obj, Rest... rest) {
    auto hash = GetHash<T>(obj);
    seed ^= hash + 0x9e3779b9 + (seed<<6) + (seed>>2);
    return CombineHash(seed, rest...);
  }

  static std::size_t CombineHash(std::size_t seed) {
    return seed;
  }
};

}  // namespace gs::backend
