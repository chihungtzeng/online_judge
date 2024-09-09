#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1, 2, 3, 4};

  EXPECT_EQ(sol.numberOfArithmeticSlices(nums), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1, 2, 3, 4, 1,3,5,7,9};

  EXPECT_EQ(sol.numberOfArithmeticSlices(nums), 3 + 6);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{1};
  vector<int> nums2{1,2};
  vector<int> nums3{1,2,3};

  EXPECT_EQ(sol.numberOfArithmeticSlices(nums), 0);
  EXPECT_EQ(sol.numberOfArithmeticSlices(nums2), 0);
  EXPECT_EQ(sol.numberOfArithmeticSlices(nums3), 1);
}

