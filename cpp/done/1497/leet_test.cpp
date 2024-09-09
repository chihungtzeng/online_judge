#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
  int k = 5;
  EXPECT_EQ(sol.canArrange(arr, k), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  int k = 7;
  EXPECT_EQ(sol.canArrange(arr, k), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  int k = 10;
  EXPECT_EQ(sol.canArrange(arr, k), false);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {-10, 10};
  int k = 2;
  EXPECT_EQ(sol.canArrange(arr, k), true);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr = {-1, 1, -2, 2, -3, 3, -4, 4};
  int k = 3;
  EXPECT_EQ(sol.canArrange(arr, k), true);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> arr = { 1000000000, -1000000000};
  int k = 1;
  EXPECT_EQ(sol.canArrange(arr, k), true);
}

