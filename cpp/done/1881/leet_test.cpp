#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maxValue("73", 6), "763");
  EXPECT_EQ(sol.maxValue("-55", 2), "-255");
  EXPECT_EQ(sol.maxValue("99", 9), "999");
  EXPECT_EQ(sol.maxValue("-13", 2), "-123");
  EXPECT_EQ(sol.maxValue("-13", 9), "-139");
  EXPECT_EQ(sol.maxValue("13", 2), "213");
  EXPECT_EQ(sol.maxValue("98", 7), "987");
  EXPECT_EQ(sol.maxValue("-132", 3), "-1323");
  EXPECT_EQ(sol.maxValue("435", 3), "4353");
  EXPECT_EQ(sol.maxValue("432", 3), "4332");
}

