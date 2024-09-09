#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 1, 3, 4, 8 };
  vector<vector<int>> queries = { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 0, 3 } };
  vector<int> expect{ 2, 1, 4, 1 };
  EXPECT_EQ(sol.minDifference(nums, queries), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 4, 5, 2, 2, 7, 10 };
  vector<vector<int>> queries = { { 2, 3 }, { 0, 2 }, { 0, 5 }, { 3, 5 } };
  vector<int> expect{ -1, 1, 1, 3 };
  EXPECT_EQ(sol.minDifference(nums, queries), expect);
}

