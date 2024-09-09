#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums1{4,1,2};
  vector<int> nums2{1,3,4,2};
  vector<int> expect{-1,3,-1};

  EXPECT_EQ(sol.nextGreaterElement(nums1, nums2), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums1{2,4};
  vector<int> nums2{1,2,3,4};
  vector<int> expect{3,-1};

  EXPECT_EQ(sol.nextGreaterElement(nums1, nums2), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums1{3, 1, 5, 6};
  vector<int> nums2{2,7,1,8,3,4,5,9,6};
  vector<int> expect{4, 8, 9, -1};

  EXPECT_EQ(sol.nextGreaterElement(nums1, nums2), expect);
}

