#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t0) {
  Solution sol;
  vector<int> nums{1};
  EXPECT_EQ(sol.longestSubarray(nums, 400000), 1);
}



TEST(kk, t1) {
  Solution sol;
  vector<int> nums{8,2,4,7};
  EXPECT_EQ(sol.longestSubarray(nums, 4), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums {10,1,2,4,7,2};
  EXPECT_EQ(sol.longestSubarray(nums, 5), 4);
}
TEST(kk, t3) {
  Solution sol;
  vector<int> nums{4,2,2,2,4,4,2,2};
  EXPECT_EQ(sol.longestSubarray(nums, 0), 3);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{3,1,4,1,5,9,2,6,2,7,1,8,2,8};
  EXPECT_EQ(sol.longestSubarray(nums, 5), 5);
}

