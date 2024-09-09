#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.reorganizeString("aab"), "aba");
  EXPECT_EQ(sol.reorganizeString("aaab"), "");
  EXPECT_EQ(sol.reorganizeString("aaabbb"), "ababab");
}

