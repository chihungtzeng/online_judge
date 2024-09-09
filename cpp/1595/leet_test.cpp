#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> cost = {{15, 96}, {36, 2}};
  EXPECT_EQ(sol.connectTwoGroups(cost), 17);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> cost = {{1, 3, 5}, {4, 1, 1}, {1, 5, 3}};
  EXPECT_EQ(sol.connectTwoGroups(cost), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> cost = {
      {2, 5, 1}, {3, 4, 7}, {8, 1, 2}, {6, 2, 4}, {3, 8, 8}};
  EXPECT_EQ(sol.connectTwoGroups(cost), 10);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> cost = 
  {{93,56,92},{53,44,18},{86,44,69},{54,60,30}};

  EXPECT_EQ(sol.connectTwoGroups(cost), 172);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> cost = 
  {{21,76,97,7,47,87},{28,65,45,89,98,60},{99,59,30,38,43,69},{81,56,62,83,26,31},{28,31,74,74,34,20},{65,45,14,90,28,93},{47,60,21,27,47,77},{47,68,71,75,26,42}};


  EXPECT_EQ(sol.connectTwoGroups(cost), 188);
}

