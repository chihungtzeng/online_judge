#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 3, 2, 3 };
  EXPECT_EQ(sol.majorityElement(nums), 3);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 2, 2, 1, 1, 1, 2, 2 };
  EXPECT_EQ(sol.majorityElement(nums), 2);
}

