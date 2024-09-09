#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<string> words = { "lc", "cl", "gg" };
  EXPECT_EQ(sol.longestPalindrome(words), 6);
}

TEST(kk, t2)
{
  Solution sol;
  vector<string> words = { "ab", "ty", "yt", "lc", "cl", "ab" };
  EXPECT_EQ(sol.longestPalindrome(words), 8);
}

TEST(kk, t3)
{
  Solution sol;
  vector<string> words = { "cc", "ll", "xx" };
  EXPECT_EQ(sol.longestPalindrome(words), 2);
}

