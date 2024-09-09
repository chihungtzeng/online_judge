#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.reverseVowels("hello"), "holle");
  EXPECT_EQ(sol.reverseVowels("leetcode"), "leotcede");
  EXPECT_EQ(sol.reverseVowels("a."), "a.");
}

