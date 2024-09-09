#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string S = "ab#c", T = "ad#c";
  EXPECT_EQ(sol.backspaceCompare(S, T), true);
}

TEST(kk, t2) {
  Solution sol;
  string S = "ab##", T = "c#d#";
  EXPECT_EQ(sol.backspaceCompare(S, T), true);
}

TEST(kk, t3) {
  Solution sol;
  string S = "a##c", T = "#a#c";
  EXPECT_EQ(sol.backspaceCompare(S, T), true);
}

TEST(kk, t4) {
  Solution sol;
   string S = "a#c", T = "b";
  EXPECT_EQ(sol.backspaceCompare(S, T), false);
}

TEST(kk, t5) {
  Solution sol;
   string S = "y#fo##f", T = "y#f#o##f";
  EXPECT_EQ(sol.backspaceCompare(S, T), true);
}

