#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> intervals = { { 1, 3 }, { 6, 9 } };
  vector<int> newInterval = { 2, 5 };
  vector<vector<int>> expect{ { 1, 5 }, { 6, 9 } };
  EXPECT_EQ(sol.insert(intervals, newInterval), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> intervals = { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } };
  vector<int> newInterval = { 4, 8 };
  vector<vector<int>> expect{ { 1, 2 }, { 3, 10 }, { 12, 16 } };
  EXPECT_EQ(sol.insert(intervals, newInterval), expect);
}

