#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{5,4,0,3,1,6,2};

  EXPECT_EQ(sol.arrayNesting(nums), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums;

  EXPECT_EQ(sol.arrayNesting(nums), 0);
}

