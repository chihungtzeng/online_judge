#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.closeStrings("abc", "bca"), true);
  EXPECT_EQ(sol.closeStrings("a", "aa"), false);
  EXPECT_EQ(sol.closeStrings("cabbba", "abbccc"), true);
  EXPECT_EQ(sol.closeStrings("cabbba", "aabbss"), false);
}

