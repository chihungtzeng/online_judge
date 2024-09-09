#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 3, 1, -2, -5, 2, -4 };
  vector<int> expect{ 3, -2, 1, -5, 2, -4 };
  EXPECT_EQ(sol.rearrangeArray(nums), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { -1, 1 };
  vector<int> expect{ 1, -1 };
  EXPECT_EQ(sol.rearrangeArray(nums), expect);
}

