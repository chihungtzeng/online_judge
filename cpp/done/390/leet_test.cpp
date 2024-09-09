#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.lastRemaining(9), 6);
  EXPECT_EQ(sol.lastRemaining(8), 6);
  EXPECT_EQ(sol.lastRemaining(7), 4);
  EXPECT_EQ(sol.lastRemaining(6), 4);
  EXPECT_EQ(sol.lastRemaining(5), 2);
  EXPECT_EQ(sol.lastRemaining(4), 2);
  EXPECT_EQ(sol.lastRemaining(3), 2);
  EXPECT_EQ(sol.lastRemaining(2), 2);
  EXPECT_EQ(sol.lastRemaining(1), 1);
}

