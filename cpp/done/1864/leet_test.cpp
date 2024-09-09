#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minSwaps("111000"), 1);
  EXPECT_EQ(sol.minSwaps("010"), 0);
  EXPECT_EQ(sol.minSwaps("1110"), -1);
  EXPECT_EQ(sol.minSwaps("11100"), 1);
  EXPECT_EQ(sol.minSwaps("00111"), 1);
}

