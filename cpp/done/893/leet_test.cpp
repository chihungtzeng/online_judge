#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<string> words = { "abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx" };
  EXPECT_EQ(sol.numSpecialEquivGroups(words), 3);
}

TEST(kk, t2)
{
  Solution sol;
  vector<string> words = { "abc", "acb", "bac", "bca", "cab", "cba" };
  EXPECT_EQ(sol.numSpecialEquivGroups(words), 3);
}

