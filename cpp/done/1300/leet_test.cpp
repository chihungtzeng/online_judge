#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {4, 9, 3};
  int target = 10;
  EXPECT_EQ(sol.findBestValue(arr, target), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {2, 3, 5};
  int target = 10;
  EXPECT_EQ(sol.findBestValue(arr, target), 5);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {60864, 25176, 27249, 21296, 20204};
  int target = 56803;
  EXPECT_EQ(sol.findBestValue(arr, target), 11361);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {1, 2, 23, 24, 34, 36};
  int target = 110;
  EXPECT_EQ(sol.findBestValue(arr, target), 30);
}

