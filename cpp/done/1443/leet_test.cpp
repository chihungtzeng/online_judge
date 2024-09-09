#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
  vector<bool> hasApple = {false, false, true, false, true, true, false};
  EXPECT_EQ(sol.minTime(n, edges, hasApple), 8);
}

TEST(kk, t2) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
  vector<bool> hasApple{false, false, true, false, false, true, false};
  EXPECT_EQ(sol.minTime(n, edges, hasApple), 6);
}

TEST(kk, t3) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
  vector<bool> hasApple{false, false, false, false, false, false, false};
  EXPECT_EQ(sol.minTime(n, edges, hasApple), 0);
}

TEST(kk, t4) {
  Solution sol;
  int n = 5;
  vector<vector<int>> edges {{0,1},{0,2},{1,3},{0,4}};
  vector<bool> hasApple {false,false,false,true,false};
  EXPECT_EQ(sol.minTime(n, edges, hasApple), 4);
}


