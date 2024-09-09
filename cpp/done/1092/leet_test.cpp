#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string str1 = "abac", str2 = "cab";
  EXPECT_EQ(sol.shortestCommonSupersequence(str1, str2), "cabac");
}

TEST(kk, t2) {
  Solution sol;
  string str1 = "leetcode", str2 = "leegoogle";
  EXPECT_EQ(sol.shortestCommonSupersequence(str1, str2), "leetcgodogle");
}

