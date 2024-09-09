#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maxVowels("abciiidef", 3), 3);
  EXPECT_EQ(sol.maxVowels("aeiou", 2), 2);
  EXPECT_EQ(sol.maxVowels("leetcode", 3), 2);
  EXPECT_EQ(sol.maxVowels("rhythms", 4), 0);
  EXPECT_EQ(sol.maxVowels("tryhard", 4), 1);
}

