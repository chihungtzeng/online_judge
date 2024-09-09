#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {6,10,3};
  EXPECT_EQ(sol.countDifferentSubsequenceGCDs(nums), 5);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {5,15,40,5,6};
  EXPECT_EQ(sol.countDifferentSubsequenceGCDs(nums), 7);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums;
  srand(time(NULL));
  for(int i=0;i<100000; i++){
    nums.push_back(1 + rand() % 200000);
  }

  sol.countDifferentSubsequenceGCDs(nums);
}

