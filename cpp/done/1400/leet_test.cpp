#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "annabelle";
  int k = 2;
  EXPECT_EQ(sol.canConstruct(s, k), true);
}

TEST(kk, t2) {
  Solution sol;
  string s = "leetcode";
  int k = 3;
  EXPECT_EQ(sol.canConstruct(s, k), false);
}

TEST(kk, t3) {
  Solution sol;
  string s = "true";
  int k = 4;
  EXPECT_EQ(sol.canConstruct(s, k), true);
}

TEST(kk, t4) {
  Solution sol;
  string s = "yzyzyzyzyzyzyzy";
  int k = 2;
  EXPECT_EQ(sol.canConstruct(s, k), true);
}

TEST(kk, t5) {
  Solution sol;
  string s = "cr";
  int k = 7;
  EXPECT_EQ(sol.canConstruct(s, k), false);
}

TEST(kk, t6) {
  Solution sol;
  string s = "qlkzenwmmnpkopu";
  int k = 15;
  EXPECT_EQ(sol.canConstruct(s, k), true);
}




