#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "cdbcbbaaabab";
  int x = 4, y = 5;
  EXPECT_EQ(sol.maximumGain(s, x, y), 19);
}

TEST(kk, t2) {
  Solution sol;
  string s = "aabbaaxybbaabb";
  int x = 5, y = 4;
  EXPECT_EQ(sol.maximumGain(s, x, y), 20);
}

