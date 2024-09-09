#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 3, 1, 3, 2, 4, 3 };
  EXPECT_EQ(sol.minimumOperations(nums), 3);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 1, 2, 2, 2, 2 };
  EXPECT_EQ(sol.minimumOperations(nums), 2);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 1};
  EXPECT_EQ(sol.minimumOperations(nums), 0);
}

TEST(kk, t3_1)
{
  Solution sol;
  vector<int> nums = { 1, 1};
  EXPECT_EQ(sol.minimumOperations(nums), 1);
}

TEST(kk, t3_2)
{
  Solution sol;
  vector<int> nums = { 1, 2};
  EXPECT_EQ(sol.minimumOperations(nums), 0);
}

TEST(kk, t3_3)
{
  Solution sol;
  vector<int> nums = { 2, 2, 2, 2};
  EXPECT_EQ(sol.minimumOperations(nums), 2);
}

TEST(kk, t3_4)
{
  Solution sol;
  vector<int> nums = { 2, 2, 2, 2, 2};
  EXPECT_EQ(sol.minimumOperations(nums), 2);
}

