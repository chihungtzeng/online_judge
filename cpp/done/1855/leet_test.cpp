#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums1 = {55, 30, 5, 4, 2}, nums2 = {100, 20, 10, 10, 5};
  EXPECT_EQ(sol.maxDistance(nums1, nums2), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums1 = {2, 2, 2}, nums2 = {10, 10, 1};
  EXPECT_EQ(sol.maxDistance(nums1, nums2), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums1 = {30, 29, 19, 5}, nums2 = {25, 25, 25, 25, 25};
  EXPECT_EQ(sol.maxDistance(nums1, nums2), 2);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums1 = {5, 4}, nums2 = {3, 2};
  EXPECT_EQ(sol.maxDistance(nums1, nums2), 0);
}

