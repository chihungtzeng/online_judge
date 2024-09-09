#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = { 9, 12, 3, 7, 15 };
  int target = 5;
  EXPECT_EQ(sol.closestToTarget(arr, target), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = { 1000000, 1000000, 1000000 };
  int target = 1;
  EXPECT_EQ(sol.closestToTarget(arr, target), 999999);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = { 1, 2, 4, 8, 16 };
  int target = 0;
  EXPECT_EQ(sol.closestToTarget(arr, target), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr;
  for(int i=0; i<100000; i++){
    arr.push_back(rand() % 100000);
  }
  int target = rand() % 100000;
  EXPECT_EQ(sol.closestToTarget(arr, target), 0);
}

