#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {3, 2, 2, 4, 3};
  int target = 3;
  EXPECT_EQ(sol.minSumOfLengths(arr, target), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {7, 3, 4, 7};
  int target = 7;
  EXPECT_EQ(sol.minSumOfLengths(arr, target), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {4, 3, 2, 6, 2, 3, 4};
  int target = 6;
  EXPECT_EQ(sol.minSumOfLengths(arr, target), -1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {5, 5, 4, 4, 5};
  int target = 3;
  EXPECT_EQ(sol.minSumOfLengths(arr, target), -1);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr = {3, 1, 1, 1, 5, 1, 2, 1};
  int target = 3;
  EXPECT_EQ(sol.minSumOfLengths(arr, target), 3);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> arr{9,  12, 3,  16, 19, 11, 12, 18, 25, 22, 13, 3, 16,
                  10, 14, 2,  16, 2,  23, 12, 12, 19, 18, 5,  8, 6,
                  13, 24, 18, 11, 5,  3,  23, 9,  20, 18, 19, 7, 12,
                  18, 25,  2, 2, 11, 10, 13, 24, 25, 16, 21};
  EXPECT_EQ(sol.minSumOfLengths(arr, 15), 5);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> arr{12, 3, 1, 2, 3, 9};
  EXPECT_EQ(sol.minSumOfLengths(arr, 15), 6);
}

