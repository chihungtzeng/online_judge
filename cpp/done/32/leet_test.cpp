#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  
  EXPECT_EQ(sol.longestValidParentheses("(()"), 2);
}

TEST(kk, t2) {
  Solution sol;

  EXPECT_EQ(sol.longestValidParentheses(")()())"), 4);
  EXPECT_EQ(sol.longestValidParentheses(""), 0);
}

TEST(kk, t3) {
  Solution sol;
  
  EXPECT_EQ(sol.longestValidParentheses("()(()"), 2);
}

