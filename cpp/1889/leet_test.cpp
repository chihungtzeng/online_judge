#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> packages = {2, 3, 5};
  vector<vector<int>> boxes = {{4, 8}, {2, 8}};
  EXPECT_EQ(sol.minWastedSpace(packages, boxes), 6);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> packages = {2, 3, 5};
  vector<vector<int>> boxes = {{1, 4}, {2, 3}, {3, 4}};
  EXPECT_EQ(sol.minWastedSpace(packages, boxes), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> packages = {3, 5, 8, 10, 11, 12};
  vector<vector<int>> boxes = {{12}, {11, 9}, {10, 5, 14}};
  EXPECT_EQ(sol.minWastedSpace(packages, boxes), 9);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> packages = {4,4,9,10,1};
  vector<vector<int>> boxes = {{9},{4,8},{1,3}};
  EXPECT_EQ(sol.minWastedSpace(packages, boxes), -1);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> packages(40000, 1);
  vector<vector<int>> boxes = {{40000}};
  EXPECT_EQ(sol.minWastedSpace(packages, boxes), 599959993);
}





