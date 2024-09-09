#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{3,4,2};

  EXPECT_EQ(sol.deleteAndEarn(nums), 6);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{3, 2,4,2,3, 3};

  EXPECT_EQ(sol.deleteAndEarn(nums), 9);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{3,1,4,1,5,9,2,6,2,7,1,8,2,8};

  EXPECT_EQ(sol.deleteAndEarn(nums), 32);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{1,6,3,3,8,4,8,10,1,3};

  EXPECT_EQ(sol.deleteAndEarn(nums), 43);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums{3,3,4,3};

  EXPECT_EQ(sol.deleteAndEarn(nums), 9);
}

