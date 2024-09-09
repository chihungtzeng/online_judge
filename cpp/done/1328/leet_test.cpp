#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.breakPalindrome("abccba"), "aaccba");
  EXPECT_EQ(sol.breakPalindrome("a"), "");
  EXPECT_EQ(sol.breakPalindrome("aa"), "ab");
  EXPECT_EQ(sol.breakPalindrome("aba"), "abb");
  EXPECT_EQ(sol.breakPalindrome("abba"), "aaba");
  EXPECT_EQ(sol.breakPalindrome("aabaa"), "aabab");
}

