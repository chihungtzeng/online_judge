#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,3,5,4,7};

  EXPECT_EQ(sol.findNumberOfLIS(nums), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{2,2,2,2,2};

  EXPECT_EQ(sol.findNumberOfLIS(nums), 5);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{1,3,5,4,7,0,1,2,3};

  EXPECT_EQ(sol.findNumberOfLIS(nums), 3);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{1,3,5,4,7,0,1,2,3,4,5,6,7,8,9};

  EXPECT_EQ(sol.findNumberOfLIS(nums), 1);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums {1,2,4,3,5,4,7,2};

  EXPECT_EQ(sol.findNumberOfLIS(nums), 3);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> nums {1};

  EXPECT_EQ(sol.findNumberOfLIS(nums), 1);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> nums {1, 2};

  EXPECT_EQ(sol.findNumberOfLIS(nums), 1);
}

TEST(kk, t8) {
  Solution sol;
  vector<int> nums {1, 0};

  EXPECT_EQ(sol.findNumberOfLIS(nums), 2);
}

