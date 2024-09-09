#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  string s = "daabcbaabcbc", part = "abc";
  EXPECT_EQ(sol.removeOccurrences(s, part), "dab");
}

TEST(kk, t2)
{
  Solution sol;
  string s = "axxxxyyyyb", part = "xy";
  EXPECT_EQ(sol.removeOccurrences(s, part), "ab");
}

