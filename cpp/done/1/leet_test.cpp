#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 2, 7, 11, 15 };
  int target = 9;
  vector<int> expect{0, 1};
  EXPECT_EQ(sol.twoSum(nums, target), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 3, 2, 4 };
  int target = 6;
  vector<int> expect{1, 2};
  EXPECT_EQ(sol.twoSum(nums, target), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 3, 3 };
  int target = 6;
  vector<int> expect{0, 1};
  EXPECT_EQ(sol.twoSum(nums, target), expect);
}

