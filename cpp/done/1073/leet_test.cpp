#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> arr1 = { 1, 1, 1, 1, 1 }, arr2 = { 1, 0, 1 };
  vector<int> expect{ 1, 0, 0, 0, 0 };
  EXPECT_EQ(sol.addNegabinary(arr1, arr2), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> arr1 = { 0 }, arr2 = { 0 };
  vector<int> expect{ 0 };
  EXPECT_EQ(sol.addNegabinary(arr1, arr2), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> arr1 = { 0 }, arr2 = { 1 };
  vector<int> expect{ 1 };
  EXPECT_EQ(sol.addNegabinary(arr1, arr2), expect);
}

