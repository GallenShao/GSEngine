/*
 * Copyright (c) 2021 by GallenShao, All Rights Reserved.
 *
 * test_utils.cpp
 *
 *  Created on: 2021.09.20
 *  Author: gallenshao
 */

#include <gtest/gtest.h>

#include "utils/hash_utils.h"
#include "test_constants.h"
#include "utils/gs_logger.h"

TEST(HashTest, StringHash) {
  auto hash = gs::backend::HashUtils::GetHash(std::string("TEST_1"));
  EXPECT_EQ(hash, 15601285054051425561UL);
  hash = gs::backend::HashUtils::GetHash(std::string("TEST_2"));
  EXPECT_EQ(hash, 17830741306030324484UL);
  hash = gs::backend::HashUtils::GetHash(std::string("TEST_1"), std::string("TEST_2"));
  EXPECT_EQ(hash, 10866942577385650211UL);
}

TEST(HashTest, CharsHash) {
  auto hash_1 = gs::backend::HashUtils::GetHash("TEST_1");
  auto hash_2 = gs::backend::HashUtils::GetHash(std::string("TEST_1"));
  EXPECT_EQ(hash_1, hash_2);
}
