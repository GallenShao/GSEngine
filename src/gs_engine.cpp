/**
 * Copyright 2021 by GallenShao, All Rights Reserved.
 *
 * gs_engine.cpp
 *
 *  Created on: 2021.9.19
 *  Author: gallenshao
 */

#include "gs_engine.h"
#include "utils/gs_logger.h"
#include "renderer.h"
#include "../test/backend/test_constants.h"

#define TAG "GSEngine"

gs::GSEngine::GSEngine() {
  logger::SetMinLogLevel(LEVEL_INFO);
  LOG(LEVEL_INFO, TAG) << "Make";
}

void gs::GSEngine::flush() {
  std::vector<float> vertex = TEST_VERTEX_BUFFER;
  auto vertex_ptr = std::make_shared<std::vector<float>>(std::move(vertex));
  auto layout = gs::backend::Layout::GetSimpleLayout(0);
  auto vertex_parameter = std::make_shared<gs::backend::VertexParameter>(vertex_ptr, layout);

  std::vector<uint32_t> index = TEST_INDEX_BUFFER;
  auto index_ptr = std::make_shared<std::vector<uint32_t>>(std::move(index));
  auto index_parameter = std::make_shared<gs::backend::IndexParameter>(index_ptr);

  auto screen = gs::backend::FrameBuffer::FromExternal(0, 640, 480);

  auto fb = gs::backend::FrameBuffer::FromSize(320, 480);

  auto renderer = std::make_shared<gs::backend::Renderer>(TEST_VERTEX_SHADER, TEST_FRAGMENT_SHADER);
  renderer->SetVertices(vertex_parameter);
  renderer->SetIndices(index_parameter);
  renderer->SetUniforms(TEST_UNIFORM2, 0.5);
  renderer->SetUniforms(TEST_UNIFORM, 1.0, 1.0, 0.0, 1.0);
  renderer->SetOutput(fb);
  renderer->Render();

  std::vector<float> vertex_left = { 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                                     0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
                                     -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
                                     -1.0f, 1.0f, 0.0f, 0.0f, 1.0f };
  auto vertex_ptr_left = std::make_shared<std::vector<float>>(std::move(vertex_left));
  auto layout_left = gs::backend::Layout::GetSimpleLayout(1);
  auto vertex_parameter_left = std::make_shared<gs::backend::VertexParameter>(vertex_ptr_left, layout_left);

  auto copy_renderer = std::make_shared<gs::backend::Renderer>(TEST_VERTEX_SHADER_TEX, TEST_FRAGMENT_SHADER_TEX);
  copy_renderer->SetVertices(vertex_parameter_left);
  copy_renderer->SetIndices(index_parameter);
  copy_renderer->SetTexture("s_texColor", fb->GetColorAttachment());
  copy_renderer->SetOutput(screen);
  copy_renderer->Render();
}
