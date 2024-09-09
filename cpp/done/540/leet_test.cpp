#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,1,2,3,3,4,4,8,8};
  EXPECT_EQ(sol.singleNonDuplicate(nums), 2);
  vector<int> nums2{3,3,7,7,10,11,11};
  EXPECT_EQ(sol.singleNonDuplicate(nums2), 10);
  vector<int> nums3{37};
  EXPECT_EQ(sol.singleNonDuplicate(nums3), 37);
}

