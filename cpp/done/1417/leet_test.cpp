#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  EXPECT_EQ(sol.reformat("a0b1c2").size(), 6);
  EXPECT_EQ(sol.reformat("leetcode").size(), 0);
  EXPECT_EQ(sol.reformat("1229857369").size(), 0);
  EXPECT_EQ(sol.reformat("covid2019").size(), 9);
  EXPECT_EQ(sol.reformat("ab123").size(), 5);
}

