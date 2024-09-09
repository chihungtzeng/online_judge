#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numWays(3, 2), 4);
  EXPECT_EQ(sol.numWays(2, 4), 2);
  EXPECT_EQ(sol.numWays(4, 2), 8);
  EXPECT_EQ(sol.numWays(4, 5), 9);
  EXPECT_EQ(sol.numWays(5, 5), 21);
  EXPECT_EQ(sol.numWays(17, 39), 2356779);
  EXPECT_EQ(sol.numWays(438, 315977), 483475137);
}

