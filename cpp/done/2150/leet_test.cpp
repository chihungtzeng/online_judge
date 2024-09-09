#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 10, 6, 5, 8 };
  vector<int> expect{ 10, 8 };
  sort(expect.begin(), expect.end());
  auto actual = sol.findLonely(nums);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(expect, actual);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 1, 3, 5, 3 };
  vector<int> expect{ 1, 5 };
  sort(expect.begin(), expect.end());
  auto actual = sol.findLonely(nums);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(expect, actual);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 62, 35, 59, 55, 84, 61, 38, 87, 55, 82 };

  vector<int> expect{ 35, 59, 84, 38, 87, 82 };

  sort(expect.begin(), expect.end());
  auto actual = sol.findLonely(nums);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(expect, actual);
}

