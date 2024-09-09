#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;

  vector<int> differences = { 1, -3, 4 };
  int lower = 1, upper = 6;
  EXPECT_EQ(sol.numberOfArrays(differences, lower, upper), 2);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> differences = { 3, -4, 5, 1, -2 };
  int lower = -4, upper = 5;
  EXPECT_EQ(sol.numberOfArrays(differences, lower, upper), 4);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> differences = { 4, -7, 2 };
  int lower = 3, upper = 6;
  EXPECT_EQ(sol.numberOfArrays(differences, lower, upper), 0);
}

TEST(kk, t4)
{
  Solution sol;
  vector<int> differences = { -40 };
  int lower = -46, upper = 53;
  EXPECT_EQ(sol.numberOfArrays(differences, lower, upper), 60);
}

