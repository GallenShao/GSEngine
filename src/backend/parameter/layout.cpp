/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * layout.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "layout.h"
#include "utils/gs_logger.h"

#include <cstdio>
#include <sstream>

#define TAG "Layout"

namespace gs::backend {

void Layout::AddItem(const std::string& name, int size) {
  layout_items_.emplace_back(name, size, total_size_);
  total_size_ += size;
}

void Layout::Dump() {
  std::stringstream ss;
  for (auto& item : layout_items_) {
    ss << item.name_ << "(" << item.size_ << ") ";
  }
  LOG(LEVEL_DEBUG, TAG) << ss.str();
}

std::shared_ptr<Layout> Layout::GetSimpleLayout(int tex_count) {
  auto layout = std::make_shared<Layout>();
  layout->AddItem("a_Position", 3);
  for (int index = 0; index < tex_count; index++) {
    char tex_name[20];
    sprintf(tex_name, "a_texCoord%d", index);
    layout->AddItem(tex_name, 2);
  }
  return layout;
}

}  // namespace gs::backend