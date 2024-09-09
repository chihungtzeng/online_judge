#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1, 2, 3, 4};
  EXPECT_EQ(sol.find132pattern(nums), false);

  vector<int> nums2{3, 1, 4, 2};
  EXPECT_EQ(sol.find132pattern(nums2), true);

  vector<int> nums3{-1, 3, 2, 0};
  EXPECT_EQ(sol.find132pattern(nums3), true);

  vector<int> nums4{3,1,4,1,5};
  EXPECT_EQ(sol.find132pattern(nums4), false);

  vector<int> nums5{3,1,4,1,5,9,2,6};
  EXPECT_EQ(sol.find132pattern(nums5), true);
}


TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1,0,1,-4,-3};
  EXPECT_EQ(sol.find132pattern(nums), false);
}
TEST(kk, t3) {
  Solution sol;
  vector<int> nums{3,5,0,3,4};
  EXPECT_EQ(sol.find132pattern(nums), true);
}
