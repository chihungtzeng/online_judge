#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "5525";
  int a = 9, b = 2;
  EXPECT_EQ(sol.findLexSmallestString(s, a, b), "2050");
}
TEST(kk, t2) {
  Solution sol;
  string s = "74";
  int a = 5, b = 1;
  EXPECT_EQ(sol.findLexSmallestString(s, a, b), "24");
}

TEST(kk, t3) {
  Solution sol;
  string s = "0011";
  int a = 4, b = 2;
  EXPECT_EQ(sol.findLexSmallestString(s, a, b), "0011");
}

TEST(kk, t4) {
  Solution sol;
  string s = "43987654";
  int a = 7, b = 3;
  EXPECT_EQ(sol.findLexSmallestString(s, a, b), "00553311");
}

