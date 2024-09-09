#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  string s;
  int k =0;

  s = "abcd", k = 2;
  EXPECT_EQ(sol.removeDuplicates(s, k), "abcd");

  s = "deeedbbcccbdaa", k = 3;
  EXPECT_EQ(sol.removeDuplicates(s, k), "aa");

  s = "pbbcggttciiippooaais", k = 2;
  EXPECT_EQ(sol.removeDuplicates(s, k), "ps");
}

