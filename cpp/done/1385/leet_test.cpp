#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr1 = {4, 5, 8}, arr2 = {10, 9, 1, 8};
  int d = 2;
  EXPECT_EQ(sol.findTheDistanceValue(arr1, arr2, d), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr1 = {1, 4, 2, 3}, arr2 = {-4, -3, 6, 10, 20, 30};
  int d = 3;
  EXPECT_EQ(sol.findTheDistanceValue(arr1, arr2, d), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr1 = {2, 1, 100, 3}, arr2 = {-5, -2, 10, -3, 7};
  int d = 6;
  EXPECT_EQ(sol.findTheDistanceValue(arr1, arr2, d), 1);
}

