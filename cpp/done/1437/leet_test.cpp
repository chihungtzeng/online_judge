#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,0,0,0,1,0,0,1};
  EXPECT_EQ(sol.kLengthApart(nums,2), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1,0,0,1,0,1};
  EXPECT_EQ(sol.kLengthApart(nums,2), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{1,1,1,1,1};
  EXPECT_EQ(sol.kLengthApart(nums,0), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{0,1,0,1};
  EXPECT_EQ(sol.kLengthApart(nums,1), true);
}

