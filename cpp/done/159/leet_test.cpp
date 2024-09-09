#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.lengthOfLongestSubstringTwoDistinct(""), 0);
  EXPECT_EQ(sol.lengthOfLongestSubstringTwoDistinct("a"), 1);
  EXPECT_EQ(sol.lengthOfLongestSubstringTwoDistinct("abc"), 2);
  EXPECT_EQ(sol.lengthOfLongestSubstringTwoDistinct("eceba"), 3);
}

TEST(kk, t2) {
  Solution sol;
  EXPECT_EQ(sol.lengthOfLongestSubstringTwoDistinct("ccaabbb"), 5);
}

