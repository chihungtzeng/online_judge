#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums1 = {2,1,-2,5}, nums2 = {3,0,-6};
  EXPECT_EQ(sol.maxDotProduct(nums1, nums2), 18);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums1 = {3,-2}, nums2 = {2,-6,7};
  EXPECT_EQ(sol.maxDotProduct(nums1, nums2), 21);
}

TEST(kk, t3) {
  Solution sol;
  vector<int>  nums1 = {-1,-1}, nums2 = {1,1};
  EXPECT_EQ(sol.maxDotProduct(nums1, nums2), -1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int>  nums1 = {3,1,4,1,5,9,2,6,2,7,1,8,2,8};
  vector<int>  nums2 = {1,4,1,4,2,1,3,5,6,2,3,7,3,0,9,5,1};
  EXPECT_EQ(sol.maxDotProduct(nums1, nums2), 297);
}


TEST(kk, t5) {
  Solution sol;
  vector<int>  nums1 = {-3,-8,3,-10,1,3,9};
  vector<int>  nums2 = {9,2,3,7,-9,1,-8,5,-1,-1};
  EXPECT_EQ(sol.maxDotProduct(nums1, nums2), 200);
}


