#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {1, 2, 4, 4, 4, 4};
  int m = 1, k = 3;
  EXPECT_EQ(sol.containsPattern(arr, m, k), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {1, 2, 1, 2, 1, 1, 1, 3};
  int m = 2, k = 2;
  EXPECT_EQ(sol.containsPattern(arr, m, k), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {1, 2, 1, 2, 1, 3};
  int m = 2, k = 3;
  EXPECT_EQ(sol.containsPattern(arr, m, k), false);
}
TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {1, 2, 3, 1, 2};
  int m = 2, k = 2;
  EXPECT_EQ(sol.containsPattern(arr, m, k), false);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr = {2, 2, 2, 2};
  int m = 2, k = 3;
  EXPECT_EQ(sol.containsPattern(arr, m, k), false);
}
TEST(kk, t6) {
  Solution sol;
  vector<int> arr = {2, 2};
  int m = 1, k = 2;
  EXPECT_EQ(sol.containsPattern(arr, m, k), true);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> arr = {2, 2, 1, 2, 2, 1, 1, 1, 2, 1};
  int m = 2, k = 2;
  EXPECT_EQ(sol.containsPattern(arr, m, k), false);
}

