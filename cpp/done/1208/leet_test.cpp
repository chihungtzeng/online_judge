#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string s, t;
  int maxCost;

  s = "abcd", t = "bcdf", maxCost = 3;
  EXPECT_EQ(sol.equalSubstring(s, t, maxCost), 3);

  s = "abcd", t = "cdef", maxCost = 3;
  EXPECT_EQ(sol.equalSubstring(s, t, maxCost), 1);

  s = "abcd", t = "acde", maxCost = 0;
  EXPECT_EQ(sol.equalSubstring(s, t, maxCost), 1);
}

