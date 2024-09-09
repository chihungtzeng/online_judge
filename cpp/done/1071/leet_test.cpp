#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  string str1 = "ABCABC", str2 = "ABC";
  EXPECT_EQ(sol.gcdOfStrings(str1, str2), "ABC");
}

TEST(kk, t2)
{
  Solution sol;
  string str1 = "ABABAB", str2 = "ABAB";
  EXPECT_EQ(sol.gcdOfStrings(str1, str2), "AB");
}

TEST(kk, t3)
{
  Solution sol;
  string str1 = "LEET", str2 = "CODE";
  EXPECT_EQ(sol.gcdOfStrings(str1, str2), "");
}

