#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "aba", t = "baba";
  EXPECT_EQ(sol.countSubstrings(s, t), 6);

#if 1
s = "ab", t = "bb";
  EXPECT_EQ(sol.countSubstrings(s, t), 3);
s = "ab", t = "bbb";
  EXPECT_EQ(sol.countSubstrings(s, t), 5);

s = "a", t = "a";
  EXPECT_EQ(sol.countSubstrings(s, t), 0);

  s = "abe", t = "bbc";
  EXPECT_EQ(sol.countSubstrings(s, t), 10);
#endif

}

