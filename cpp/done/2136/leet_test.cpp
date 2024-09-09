#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> plantTime = { 1, 4, 3 }, growTime = { 2, 3, 1 };
  EXPECT_EQ(sol.earliestFullBloom(plantTime, growTime), 9);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> plantTime = { 1, 2, 3, 2 }, growTime = { 2, 1, 2, 1 };
  EXPECT_EQ(sol.earliestFullBloom(plantTime, growTime), 9);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> plantTime = { 1 }, growTime = { 1 };
  EXPECT_EQ(sol.earliestFullBloom(plantTime, growTime), 2);
}

