#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "abcabcbb";
  EXPECT_EQ(sol.lengthOfLongestSubstring(s), 3);
}

TEST(kk, t2) {
  Solution sol;
  string s = "bbbbb";
  EXPECT_EQ(sol.lengthOfLongestSubstring(s), 1);
}

TEST(kk, t3) {
  Solution sol;
  string s = "pwwkew";
  EXPECT_EQ(sol.lengthOfLongestSubstring(s), 3);
}

TEST(kk, t4) {
  Solution sol;
  string s = "";
  EXPECT_EQ(sol.lengthOfLongestSubstring(s), 0);
  s = "z";
  EXPECT_EQ(sol.lengthOfLongestSubstring(s), 1);
}

