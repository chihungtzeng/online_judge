#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1,2};
  EXPECT_EQ(sol.maxScore(nums), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {3,4,6,8};
  EXPECT_EQ(sol.maxScore(nums), 11);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1,2,3,4,5,6};
  EXPECT_EQ(sol.maxScore(nums), 14);
}

TEST(kk, t3_1) {
  Solution sol;
  vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
  EXPECT_EQ(sol.maxScore(nums), 14);
}



TEST(kk, t4) {
  Solution sol;
  int diff = 0;
  vector<int> nums;
  while(nums.size() < 14) {
    nums.push_back(1000000 - diff);
    diff++;
  }
  LOG(INFO) << nums;
  EXPECT_EQ(sol.maxScore(nums), 14);
}

