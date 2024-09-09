#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.removeDuplicateLetters("bcabc"), "abc");
  EXPECT_EQ(sol.removeDuplicateLetters("cbacdcbc"), "acdb");
  EXPECT_EQ(sol.removeDuplicateLetters("bacb"), "acb");
  EXPECT_EQ(sol.removeDuplicateLetters("abacb"), "abc");
}

