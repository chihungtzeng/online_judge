#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<string> startWords = { "ant", "act", "tack" }, targetWords = { "tack", "act", "acti" };
  EXPECT_EQ(sol.wordCount(startWords, targetWords), 2);
}

TEST(kk, t2)
{
  Solution sol;
  vector<string> startWords = { "ab", "a" }, targetWords = { "abc", "abcd" };
  EXPECT_EQ(sol.wordCount(startWords, targetWords), 1);
}

