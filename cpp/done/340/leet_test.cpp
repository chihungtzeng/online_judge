#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("eceba", 2), 3);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("aa", 1), 2);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("aabbbccabababab", 1), 3);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("31415926271828", 1), 1);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("31415926271828", 2), 3);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("31415926271828", 3), 4);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("31415926271828", 4), 6);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("31415926271828", 5), 8);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("31415926271828", 6), 9);
  EXPECT_EQ(sol.lengthOfLongestSubstringKDistinct("31415926271828", 7), 11);
}

