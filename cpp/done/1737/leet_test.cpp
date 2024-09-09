#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

#if 1
  EXPECT_EQ(sol.minCharacters("aba", "caa"), 2);
  EXPECT_EQ(sol.minCharacters("dabadd", "cda"), 3);
  EXPECT_EQ(sol.minCharacters("leetcodeandfacebook", "googleandnetflixplusapple"), 14);
  EXPECT_EQ(sol.minCharacters("azzzz", "bzzzz"), 2);
#endif  
  EXPECT_EQ(sol.minCharacters("a", "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"), 2);
}

