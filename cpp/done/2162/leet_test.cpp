#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  int startAt = 1, moveCost = 2, pushCost = 1, targetSeconds = 600;
  EXPECT_EQ(sol.minCostSetTime(startAt, moveCost, pushCost, targetSeconds), 6);
}

TEST(kk, t2) {
  Solution sol;

  int startAt = 0, moveCost = 1, pushCost = 2, targetSeconds = 76;
  EXPECT_EQ(sol.minCostSetTime(startAt, moveCost, pushCost, targetSeconds), 6);
}

TEST(kk, t3) {
  Solution sol;

  int startAt = 1, moveCost = 9403, pushCost = 9402, targetSeconds = 6008;
  EXPECT_EQ(sol.minCostSetTime(startAt, moveCost, pushCost, targetSeconds), 65817);
}

