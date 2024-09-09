#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums1{7,4};
  vector<int> nums2 = {5,2,8,9};

  EXPECT_EQ(sol.numTriplets(nums1, nums2), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums1{1,1};
  vector<int> nums2{1,1,1};

  EXPECT_EQ(sol.numTriplets(nums1, nums2), 9);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums1 {7,7,8,3};
  vector<int> nums2 {1,2,9,7};

  EXPECT_EQ(sol.numTriplets(nums1, nums2), 2);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums1{4,7,9,11,23};
  vector<int> nums2{3,5,1024,12,18};

  EXPECT_EQ(sol.numTriplets(nums1, nums2), 0);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums1{ 43024,99908 };
  vector<int> nums2{1864};

  EXPECT_EQ(sol.numTriplets(nums1, nums2), 0);
}

