#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"
TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
  int k = 3, threshold = 4;
  EXPECT_EQ(sol.numOfSubarrays(arr, k, threshold), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {1, 1, 1, 1, 1};
  int k = 1, threshold = 0;
  EXPECT_EQ(sol.numOfSubarrays(arr, k, threshold), 5);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
  int k = 3, threshold = 5;
  EXPECT_EQ(sol.numOfSubarrays(arr, k, threshold), 6);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {7, 7, 7, 7, 7, 7, 7};
  int k = 7, threshold = 7;
  EXPECT_EQ(sol.numOfSubarrays(arr, k, threshold), 1);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr = {4, 4, 4, 4};
  int k = 4, threshold = 1;
  EXPECT_EQ(sol.numOfSubarrays(arr, k, threshold), 1);
}

