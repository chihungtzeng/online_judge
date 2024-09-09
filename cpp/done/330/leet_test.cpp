#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,3};

  EXPECT_EQ(sol.minPatches(nums, 6), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1,5,10};

  EXPECT_EQ(sol.minPatches(nums, 20), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{1,2,2};

  EXPECT_EQ(sol.minPatches(nums, 5), 0);
}


TEST(kk, t4) {
  Solution sol;
  vector<int> nums{1,2,31,33};


  EXPECT_EQ(sol.minPatches(nums, 2147483647), 28);
  }
