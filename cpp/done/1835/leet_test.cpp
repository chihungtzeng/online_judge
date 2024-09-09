#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr1 = {1, 2, 3}, arr2 = {6, 5};
  EXPECT_EQ(sol.getXORSum(arr1, arr2), 0);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr1 = {12}, arr2 = {4};
  EXPECT_EQ(sol.getXORSum(arr1, arr2), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr1{883, 1920, 4162, 10265, 2671, 9073, 9094, 7127, 216, 9289},
      arr2{11035, 6140, 1097, 3690, 11073, 11244, 4648, 8442, 818, 9128};
  EXPECT_EQ(sol.getXORSum(arr1, arr2), 32);
}

