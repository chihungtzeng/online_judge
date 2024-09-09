#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4}, quantity = {2};
  EXPECT_EQ(sol.canDistribute(nums, quantity), false);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 3}, quantity = {2};
  EXPECT_EQ(sol.canDistribute(nums, quantity), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1, 1, 2, 2}, quantity = {2, 2};
  EXPECT_EQ(sol.canDistribute(nums, quantity), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {1, 1, 2, 3}, quantity = {2, 2};
  EXPECT_EQ(sol.canDistribute(nums, quantity), false);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {1, 1, 1, 1, 1}, quantity = {2, 3};
  EXPECT_EQ(sol.canDistribute(nums, quantity), true);
}

TEST(kk, t6) {
  Solution sol;
  
  vector<int> nums, quantity;
  srand(time(NULL));
  for(int i=1; i<=100000; i++){
    nums.push_back(1 + rand() % 999);
  }
  for(int i=1; i<=10; i++){
    quantity.push_back(1 + rand() % 99999);
  }

  EXPECT_EQ(sol.canDistribute(nums, quantity), true);
}
