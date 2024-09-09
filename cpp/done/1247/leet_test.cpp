#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  string s1, s2;
  s1 = "xx", s2 = "yy";
  EXPECT_EQ(sol.minimumSwap(s1, s2), 1);

  s1 = "xy", s2 = "yx";
  EXPECT_EQ(sol.minimumSwap(s1, s2), 2);

  s1 = "xx", s2 = "xy";
  EXPECT_EQ(sol.minimumSwap(s1, s2), -1);

  s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx";
  EXPECT_EQ(sol.minimumSwap(s1, s2), 4);
}

