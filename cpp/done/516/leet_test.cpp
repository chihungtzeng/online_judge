#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.longestPalindromeSubseq("bbbab"), 4);
  EXPECT_EQ(sol.longestPalindromeSubseq("cbbd"), 2);
  EXPECT_EQ(sol.longestPalindromeSubseq(""), 0);
}

