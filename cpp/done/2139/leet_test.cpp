#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  int target = 5, maxDoubles = 0;
  EXPECT_EQ(sol.minMoves(target, maxDoubles), 4);

  target = 19, maxDoubles = 2;
  EXPECT_EQ(sol.minMoves(target, maxDoubles), 7);

  target = 10, maxDoubles = 4;
  EXPECT_EQ(sol.minMoves(target, maxDoubles), 4);
}

