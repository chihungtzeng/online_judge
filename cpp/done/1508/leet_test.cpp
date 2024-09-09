#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1,2,3,4};
  int n = 4, left = 1, right = 5;
  EXPECT_EQ(sol.rangeSum(nums,n,left,right), 13);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1,2,3,4};
  int n = 4, left = 3, right = 4;
  EXPECT_EQ(sol.rangeSum(nums,n,left,right), 6);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1,2,3,4};
  int n = 4, left = 1, right = 10;
  EXPECT_EQ(sol.rangeSum(nums,n,left,right), 50);
}

