#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 0, 1, 0, 1, 1, 0, 0 };
  EXPECT_EQ(sol.minSwaps(nums), 1);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 0, 1, 1, 1, 0, 0, 1, 1, 0 };
  EXPECT_EQ(sol.minSwaps(nums), 2);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 1, 1, 0, 0, 1 };
  EXPECT_EQ(sol.minSwaps(nums), 0);
}

TEST(kk, t4)
{
  Solution sol;
  vector<int> nums = { 1};
  EXPECT_EQ(sol.minSwaps(nums), 0);
}

TEST(kk, t5)
{
  Solution sol;
  vector<int> nums = {1,1,1,0,0,1,0,1,1,0} ;
  EXPECT_EQ(sol.minSwaps(nums), 1);
}

