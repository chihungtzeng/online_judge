#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> triplets = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
  vector<int> target = {2, 7, 5};
  EXPECT_EQ(sol.mergeTriplets(triplets, target), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> triplets = {{1, 3, 4}, {2, 5, 8}};
  vector<int> target = {2, 5, 8};
  EXPECT_EQ(sol.mergeTriplets(triplets, target), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> triplets = {{2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3}};
  vector<int> target = {5, 5, 5};
  EXPECT_EQ(sol.mergeTriplets(triplets, target), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> triplets = {{3, 4, 5}, {4, 5, 6}};
  vector<int> target = {3, 2, 5};
  EXPECT_EQ(sol.mergeTriplets(triplets, target), false);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> triplets = {{1, 5, 8}, {2,3,9}};
  vector<int> target = {1,5,9};
  EXPECT_EQ(sol.mergeTriplets(triplets, target), false);
}


