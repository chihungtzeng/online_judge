#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 5;
  vector<vector<int>> requests = {{0, 1}, {1, 0}, {0, 1},
                                  {1, 2}, {2, 0}, {3, 4}};
  EXPECT_EQ(sol.maximumRequests(n, requests), 5);
}

TEST(kk, t2) {
  Solution sol;
  int n = 3;
  vector<vector<int>> requests = {{0, 0}, {1, 2}, {2, 1}};
  EXPECT_EQ(sol.maximumRequests(n, requests), 3);
}

TEST(kk, t3) {
  Solution sol;
  int n = 4;
  vector<vector<int>> requests = {{0, 3}, {3, 1}, {1, 2}, {2, 0}};
  EXPECT_EQ(sol.maximumRequests(n, requests), 4);
}

TEST(kk, t4) {
  Solution sol;
  int n = 3;
  vector<vector<int>> requests = {{0,0},{1,1},{0,0},{2,0},{2,2},{1,1},{2,1},{0,1},{0,1}};

  EXPECT_EQ(sol.maximumRequests(n, requests), 5);
}

