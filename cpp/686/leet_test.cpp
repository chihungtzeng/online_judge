#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;

  EXPECT_EQ(sol.repeatedStringMatch("abcd", "cdabcdab"), 3);
  EXPECT_EQ(sol.repeatedStringMatch("a", "aa"), 2);
  EXPECT_EQ(sol.repeatedStringMatch("aa", "a"), 1);
  EXPECT_EQ(sol.repeatedStringMatch("aabaaabaaac", "aabaaac"), 1);
}

TEST(kk, t2)
{
  Solution sol;
  EXPECT_EQ(sol.repeatedStringMatch("abc", "cabcabca"), 1);
}
