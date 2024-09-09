#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maxUniqueSplit("ababccc"), 5);
  EXPECT_EQ(sol.maxUniqueSplit("aba"), 2);
  EXPECT_EQ(sol.maxUniqueSplit("aa"), 1);
  EXPECT_EQ(sol.maxUniqueSplit("aaa"), 2);
  EXPECT_EQ(sol.maxUniqueSplit("a"), 1);
}

