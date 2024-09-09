#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> piles = { 3, 6, 7, 11 };
  int h = 8;
  EXPECT_EQ(sol.minEatingSpeed(piles, h), 4);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> piles = { 30, 11, 23, 4, 20 };
  int h = 5;
  EXPECT_EQ(sol.minEatingSpeed(piles, h), 30);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> piles = { 30, 11, 23, 4, 20 };
  int h = 6;
  EXPECT_EQ(sol.minEatingSpeed(piles, h), 23);
}

