#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countArrangement(1), 1);
  EXPECT_EQ(sol.countArrangement(2), 2);
  EXPECT_EQ(sol.countArrangement(3), 3);
  EXPECT_EQ(sol.countArrangement(4), 8);
  EXPECT_EQ(sol.countArrangement(5), 10);
  EXPECT_EQ(sol.countArrangement(6), 36);
  EXPECT_EQ(sol.countArrangement(7), 41);
  EXPECT_EQ(sol.countArrangement(8), 132);
  EXPECT_EQ(sol.countArrangement(9), 250);
  EXPECT_EQ(sol.countArrangement(10), 700);
  EXPECT_EQ(sol.countArrangement(11), 750);
  EXPECT_EQ(sol.countArrangement(12), 4010);
  EXPECT_EQ(sol.countArrangement(13), 4237);
  EXPECT_EQ(sol.countArrangement(14), 10680);
  EXPECT_EQ(sol.countArrangement(15), 24679);
}

