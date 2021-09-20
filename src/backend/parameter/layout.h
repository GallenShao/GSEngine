/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * layout.h
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

namespace gs::backend {

class LayoutItem {
 public:
  LayoutItem(const std::string& name, int size, int offset) : name_(name), size_(size), offset_(offset) {}

  std::string name_;
  int size_;
  int offset_;
};

class Layout {
 public:
  Layout() = default;
  void AddItem(const std::string& name, int size);

  void Dump();

  static std::shared_ptr<Layout> GetSimpleLayout(int tex_count);

  std::vector<LayoutItem> layout_items_;
  int total_size_ = 0;
};

}  // namespace gs::backend
