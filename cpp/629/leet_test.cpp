#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.kInversePairs(3, 0), 1);
  EXPECT_EQ(sol.kInversePairs(3, 1), 2);
  EXPECT_EQ(sol.kInversePairs(5, 3), 15);
  EXPECT_EQ(sol.kInversePairs(5, 4), 20);
  EXPECT_EQ(sol.kInversePairs(1000, 1000), 663677020);
}

