#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 4, 5, 6}, nums2 = {1, 1, 2, 2, 2, 2};
  EXPECT_EQ(sol.minOperations(nums1, nums2), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums1 = {1, 1, 1, 1, 1, 1, 1}, nums2 = {6};
  EXPECT_EQ(sol.minOperations(nums1, nums2), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums1 = {6, 6}, nums2 = {1};
  EXPECT_EQ(sol.minOperations(nums1, nums2), 3);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums1 = {5,6,4,3,1,2}, nums2 = {6,3,3,1,4,5,3,4,1,3,4};
  EXPECT_EQ(sol.minOperations(nums1, nums2), 4);
}

