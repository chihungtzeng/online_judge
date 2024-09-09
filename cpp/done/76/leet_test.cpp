#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  string s = "ADOBECODEBANC", t = "ABC";
  EXPECT_EQ(sol.minWindow(s, t), "BANC");
}

TEST(kk, t2)
{
  Solution sol;
  string s = "a", t = "a";
  EXPECT_EQ(sol.minWindow(s, t), "a");
}

TEST(kk, t3)
{
  Solution sol;
  string s = "a", t = "aa";
  EXPECT_EQ(sol.minWindow(s, t), "");
}

TEST(kk, t4)
{
  Solution sol;
  string s = "cabwefgewcwaefgcf", t = "cae";
  EXPECT_EQ(sol.minWindow(s, t), "cwae");
}

