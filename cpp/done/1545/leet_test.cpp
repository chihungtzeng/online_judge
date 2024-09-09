#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.findKthBit(3, 1), '0');
  EXPECT_EQ(sol.findKthBit(4, 11), '1');
  EXPECT_EQ(sol.findKthBit(1, 1), '0');
  EXPECT_EQ(sol.findKthBit(2, 3), '1');
  EXPECT_EQ(sol.findKthBit(20, 1047576), '0');
}

