#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minSteps(1), 0);
  EXPECT_EQ(sol.minSteps(2), 2);
  EXPECT_EQ(sol.minSteps(3), 3);
  EXPECT_EQ(sol.minSteps(4), 4);
  EXPECT_EQ(sol.minSteps(5), 5);
  EXPECT_EQ(sol.minSteps(6), 5);
  EXPECT_EQ(sol.minSteps(7), 7);
  EXPECT_EQ(sol.minSteps(8), 6);
  EXPECT_EQ(sol.minSteps(9), 6);
  EXPECT_EQ(sol.minSteps(22), 13);
  EXPECT_EQ(sol.minSteps(25), 10);
  EXPECT_EQ(sol.minSteps(27), 9);
  EXPECT_EQ(sol.minSteps(81), 12);
}

TEST(kk, t2) {
  Solution sol;

  EXPECT_EQ(sol.minSteps(27), 9);
} 
