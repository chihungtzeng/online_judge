#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1,2,5,9}; int threshold = 6;
  EXPECT_EQ(sol.smallestDivisor(nums, threshold), 5);
}
TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2,3,5,7,11}; int threshold = 11;
  EXPECT_EQ(sol.smallestDivisor(nums, threshold), 3);
}
TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {19}; int threshold = 5;
  EXPECT_EQ(sol.smallestDivisor(nums, threshold), 4);
}

