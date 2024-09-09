#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums1{1,2,2,1};
  vector<int> nums2{2,2};
  vector<int> expect{2};

  EXPECT_EQ(sol.intersection(nums1, nums2), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums1{4,9,5,111111};
  vector<int> nums2{9,4,9,8,4,111111};
  vector<int> expect{4,9,111111};

  EXPECT_EQ(sol.intersection(nums1, nums2), expect);
}

