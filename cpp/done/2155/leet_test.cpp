#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 0, 0, 1, 0 };
  vector<int> expect{ 2, 4 };
  EXPECT_EQ(sol.maxScoreIndices(nums), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 0, 0, 0 };
  vector<int> expect{ 3 };
  EXPECT_EQ(sol.maxScoreIndices(nums), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 1, 1 };
  vector<int> expect{ 0 };
  EXPECT_EQ(sol.maxScoreIndices(nums), expect);
}

