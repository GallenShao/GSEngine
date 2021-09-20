/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * vertex_buffer.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include "vertex_buffer.h"

#define TAG "VertexBuffer"

namespace gs {

VertexBuffer::VertexBuffer(const std::shared_ptr<std::vector<float>>& data)
    : Buffer(BufferType::ARRAY_BUFFER, data->data(), data->size(), sizeof(float)), data_(data) {}

}  // namespace gs
