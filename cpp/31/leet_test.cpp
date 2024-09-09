#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 1, 2, 3 };
  vector<int> expect{ 1, 3, 2 };
  sol.nextPermutation(nums);
  EXPECT_EQ(nums, expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 3, 2, 1 };
  vector<int> expect{ 1, 2, 3 };
  sol.nextPermutation(nums);
  EXPECT_EQ(nums, expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 1, 1, 5 };
  vector<int> expect{ 1, 5, 1 };
  sol.nextPermutation(nums);
  EXPECT_EQ(nums, expect);
}

TEST(kk, t4)
{
  Solution sol;
  vector<int> nums = { 1, 2 };
  vector<int> expect{ 2, 1 };

  sol.nextPermutation(nums);
  EXPECT_EQ(nums, expect);
}

TEST(kk, t5)
{
  Solution sol;
  vector<int> nums = { 1 };
  vector<int> expect{ 1 };
  sol.nextPermutation(nums);
  EXPECT_EQ(nums, expect);
}

