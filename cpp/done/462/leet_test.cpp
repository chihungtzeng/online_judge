#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,2,3};

  vector<int> nums2{3,1,4,1,5};
  EXPECT_EQ(sol.minMoves2(nums2), 7);


  vector<int> nums3{3,1,4,1,5,9,2,6,2,7,1,8,2,8};
  EXPECT_EQ(sol.minMoves2(nums3), 35);

  vector<int> nums4{1,0,0,8,6};
  EXPECT_EQ(sol.minMoves2(nums4), 14);
}

