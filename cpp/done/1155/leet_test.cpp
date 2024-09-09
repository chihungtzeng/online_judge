#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  int d = 1, f = 6, target = 3;
  EXPECT_EQ(sol.numRollsToTarget(d, f, target), 1);

  d = 2, f = 6, target = 7;
  EXPECT_EQ(sol.numRollsToTarget(d, f, target), 6);

  d = 2, f = 1, target = 1;
  EXPECT_EQ(sol.numRollsToTarget(d, f, target), 0);

  d = 1, f = 1, target = 1;
  EXPECT_EQ(sol.numRollsToTarget(d, f, target), 1);

  d = 2, f = 5, target = 10;
  EXPECT_EQ(sol.numRollsToTarget(d, f, target), 1);

  d = 1, f = 2, target = 3;
  EXPECT_EQ(sol.numRollsToTarget(d, f, target), 0);

  d = 30, f = 30, target = 500;
  EXPECT_EQ(sol.numRollsToTarget(d, f, target), 222616187);

  d = 30, f = 30, target = 1000;
  EXPECT_EQ(sol.numRollsToTarget(d, f, target), 0);
}

