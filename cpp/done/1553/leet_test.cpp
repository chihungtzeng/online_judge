#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minDays(1), 1);
  EXPECT_EQ(sol.minDays(6), 3);
  EXPECT_EQ(sol.minDays(10), 4);
  EXPECT_EQ(sol.minDays(2000000000), 32);
}

TEST(kk, t2) {
  Solution sol;
  EXPECT_EQ(sol.minDays(56), 6);
}
