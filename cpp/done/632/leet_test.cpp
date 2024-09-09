#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> nums = { { 4, 10, 15, 24, 26 }, { 0, 9, 12, 20 }, { 5, 18, 22, 30 } };
  vector<int> expect{ 20, 24 };
  EXPECT_EQ(sol.smallestRange(nums), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> nums = { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } };
  vector<int> expect{ 1, 1 };
  EXPECT_EQ(sol.smallestRange(nums), expect);
}

