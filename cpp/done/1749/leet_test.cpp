#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1,-3,2,3,-4};
  EXPECT_EQ(sol.maxAbsoluteSum(nums), 5);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2,-5,1,-4,3,-2};
  EXPECT_EQ(sol.maxAbsoluteSum(nums), 8);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {-36, 90, -80, 66, -30, -59, -3, -97, 67, 73, -28, -53, -10, -71, 84, -45, -88, -46, 34, -1, 0, 32, -20, -84, -83, 19, -25, -23, -86, 76, 28, -86, -49, -57, -10, 31, -8, -22, 26, -75, 50, 91, -65, -59, -7, 0, 60, 100, 81, 44, -76, -67, -74, 46, -93, 80, 30, 12, 19, -2, 81, 69, 84, -75, 75, 23, -34, 64, -12, 70, -46, -97, -63, 75, -100, -11, -8, -22, 83, -47, 39, 90, -79, -22, -45, -47, 47, -71, -92, 84, -38, -87, -19, 13, 45, 90, 56, -37, 12, -59};
  EXPECT_EQ(sol.maxAbsoluteSum(nums), 703);
}


