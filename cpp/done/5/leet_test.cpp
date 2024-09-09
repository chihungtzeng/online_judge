#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.longestPalindrome("babad"), "bab");
  EXPECT_EQ(sol.longestPalindrome("cbbd"), "bb");
  EXPECT_EQ(sol.longestPalindrome("z"), "z");
}

