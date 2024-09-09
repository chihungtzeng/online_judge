#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;

  vector<string> expect{ "((()))", "(()())", "(())()", "()(())", "()()()" };
  EXPECT_EQ(sol.generateParenthesis(3), expect);
}

TEST(kk, t2)
{
  Solution sol;

  vector<string> expect{ "()" };
  EXPECT_EQ(sol.generateParenthesis(1), expect);
}

