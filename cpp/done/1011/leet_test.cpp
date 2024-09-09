#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> weights = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int days = 5;
  EXPECT_EQ(sol.shipWithinDays(weights, days), 15);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> weights = { 3, 2, 2, 4, 1, 4 };
  int days = 3;
  EXPECT_EQ(sol.shipWithinDays(weights, days), 6);
}

TEST(kk, t3)
{
  Solution sol;

  vector<int> weights = { 1, 2, 3, 1, 1 };
  int days = 4;
  EXPECT_EQ(sol.shipWithinDays(weights, days), 3);
}

