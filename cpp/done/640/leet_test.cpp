#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  string equation = "x+5-3+x=6+x-2";
  EXPECT_EQ(sol.solveEquation(equation), "x=2");
}

TEST(kk, t2)
{
  Solution sol;
  string equation = "x=x";
  EXPECT_EQ(sol.solveEquation(equation), "Infinite solutions");
}

TEST(kk, t3)
{
  Solution sol;
  string equation = "2x=x";
  EXPECT_EQ(sol.solveEquation(equation), "x=0");
}

