#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.longestPrefix("level"), "l");
  EXPECT_EQ(sol.longestPrefix("ababab"), "abab");
  EXPECT_EQ(sol.longestPrefix("leetcodeleet"), "leet");
  EXPECT_EQ(sol.longestPrefix("a"), "");
}

