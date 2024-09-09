#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<string> tokens = { "2", "1", "+", "3", "*" };
  EXPECT_EQ(sol.evalRPN(tokens), 9);
}

TEST(kk, t2)
{
  Solution sol;
  vector<string> tokens = { "4", "13", "5", "/", "+" };
  EXPECT_EQ(sol.evalRPN(tokens), 6);
}

TEST(kk, t3)
{
  Solution sol;
  vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
  EXPECT_EQ(sol.evalRPN(tokens), 22);
}

TEST(kk, t4)
{
  Solution sol;
  vector<string> tokens = { "4", "3", "-"};
  EXPECT_EQ(sol.evalRPN(tokens), 1);
}

TEST(kk, t5)
{
  Solution sol;
  vector<string> tokens = {"-128","-128","*","-128","*","-128","*","8","*","-1","*"};

  EXPECT_EQ(sol.evalRPN(tokens), -2147483648);
}

