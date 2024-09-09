#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;

  vector<int> price = { 2, 5 };
  vector<vector<int>> special = { { 3, 0, 5 }, { 1, 2, 10 } };
  vector<int> needs = { 3, 2 };
  EXPECT_EQ(sol.shoppingOffers(price, special, needs), 14);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> price = { 2, 3, 4 };
  vector<vector<int>> special = { { 1, 1, 0, 4 }, { 2, 2, 1, 9 } };
  vector<int> needs = { 1, 2, 1 };
  EXPECT_EQ(sol.shoppingOffers(price, special, needs), 11);
}

