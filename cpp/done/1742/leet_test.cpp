#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countBalls(1, 10), 2);
  EXPECT_EQ(sol.countBalls(5, 15), 2);
  EXPECT_EQ(sol.countBalls(1, 100000), 6000);
}

