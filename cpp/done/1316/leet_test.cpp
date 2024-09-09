#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string text = "abcabcabc";
  EXPECT_EQ(sol.distinctEchoSubstrings(text), 3);
}

TEST(kk, t2) {
  Solution sol;
  string text = "leetcodeleetcode";
  EXPECT_EQ(sol.distinctEchoSubstrings(text), 2);
}

