#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{2,2,3,4};

  EXPECT_EQ(sol.triangleNumber(nums), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{3,1,4,1,5,9,2,6};

  EXPECT_EQ(sol.triangleNumber(nums), 9);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{3,1,4,1,5,9,2,6,2,7,1,8,2,8};

  EXPECT_EQ(sol.triangleNumber(nums), 91);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{0,0,0};

  EXPECT_EQ(sol.triangleNumber(nums), 0);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums{7,7,7};

  EXPECT_EQ(sol.triangleNumber(nums), 1);
}

