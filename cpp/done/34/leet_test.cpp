#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 5, 7, 7, 8, 8, 10 };
  int target = 8;
  vector<int> expect{ 3, 4 };
  EXPECT_EQ(sol.searchRange(nums, target), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 5, 7, 7, 8, 8, 10 };
  int target = 6;
  vector<int> expect{ -1, -1 };
  EXPECT_EQ(sol.searchRange(nums, target), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = {};
  int target = 0;
  vector<int> expect{ -1, -1 };
  EXPECT_EQ(sol.searchRange(nums, target), expect);
}

TEST(kk, t4)
{
  Solution sol;
  vector<int> nums = {2, 2};
  int target = 3;
  vector<int> expect{ -1, -1 };
  EXPECT_EQ(sol.searchRange(nums, target), expect);
}

