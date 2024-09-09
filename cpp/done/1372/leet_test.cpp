#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.findTheLongestSubstring("eleetminicoworoep"), 13);
  EXPECT_EQ(sol.findTheLongestSubstring("leetcodeisgreat"), 5);
  EXPECT_EQ(sol.findTheLongestSubstring("bcbcbc"), 6);
}

