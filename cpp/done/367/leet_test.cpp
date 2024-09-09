#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.isPerfectSquare(16), true);
  EXPECT_EQ(sol.isPerfectSquare(0), true);
  EXPECT_EQ(sol.isPerfectSquare(1), true);
  EXPECT_EQ(sol.isPerfectSquare(808201), true);
  EXPECT_EQ(sol.isPerfectSquare(14), false);
  EXPECT_EQ(sol.isPerfectSquare(-14), false);
}

