#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
  int d = 2;
  EXPECT_EQ(sol.maxJumps(arr, d), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {3, 3, 3, 3, 3};
  int d = 3;
  EXPECT_EQ(sol.maxJumps(arr, d), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {7, 6, 5, 4, 3, 2, 1};
  int d = 1;
  EXPECT_EQ(sol.maxJumps(arr, d), 7);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {7, 1, 7, 1, 7, 1};
  int d = 2;
  EXPECT_EQ(sol.maxJumps(arr, d), 2);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr = {66};
  int d = 1;
  EXPECT_EQ(sol.maxJumps(arr, d), 1);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> arr = {39,1,1,19,40,34,87,44,30,3,89,55,81,97,84,52,10,8,96,69,17,48,93,84,10,48,1,93,65,24,100,26,24,33,52,17,15,26,8,87,69,47,61,58,78,52,2,72,23,9,3,27,36,38,88,20,21,79,5,67,22,24,39,7,17,29,3,97,36,51,91,53,98,48,83,52,14,71,91,46,42,88,44,52,74,8,39,11,48,59,98,34,43,94,46,20,26,62,6,36,59,77,23,93,6,93,64,18,33,69,56,48,54,98,98,53,14,97,47,50,33,87,10,51,92,1,14,27,19,34,83,65,48,44,82,51,81,83,23,8,63,70,76,83,46,84,20,7,37,4,69,63,84,71,91,78,58,25,63,85,98,78,21};
  int d = 62;
  EXPECT_EQ(sol.maxJumps(arr, d), 13);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> arr = {8, 5, 14};
  int d = 3;
  EXPECT_EQ(sol.maxJumps(arr, d), 3);
}


