#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;

  vector<int> candidates = { 2, 3, 6, 7 };
  int target = 7;
  vector<vector<int>> expect{ { 2, 2, 3 }, { 7 } };
  EXPECT_EQ(sol.combinationSum(candidates, target), expect);
}

TEST(kk, t2)
{
  Solution sol;

  vector<int> candidates = { 2, 3, 5 };
  int target = 8;
  vector<vector<int>> expect{ { 2, 2, 2, 2 }, { 2, 3, 3 }, { 3, 5 } };

  EXPECT_EQ(sol.combinationSum(candidates, target), expect);
}

TEST(kk, t3)
{
  Solution sol;

  vector<int> candidates = { 2 };
  int target = 1;
  vector<vector<int>> expect;
  EXPECT_EQ(sol.combinationSum(candidates, target), expect);
}

