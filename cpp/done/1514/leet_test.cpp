#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 3;
  vector<vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 0, 2 } };
  vector<double> succProb = { 0.5, 0.5, 0.2 };
  int start = 0, end = 2;
  EXPECT_EQ(sol.maxProbability(n, edges, succProb, start, end), 0.25);
}

TEST(kk, t2) {
  Solution sol;
  int n = 3;
  vector<vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 0, 2 } };
  vector<double> succProb = { 0.5, 0.5, 0.3 };
  int start = 0, end = 2;
  EXPECT_EQ(sol.maxProbability(n, edges, succProb, start, end), 0.3);
}

TEST(kk, t3) {
  Solution sol;
  int n = 3;
  vector<vector<int>> edges = {{ 0, 1 }};
  vector<double> succProb = {0.5};
  int start = 0, end = 2;
  EXPECT_EQ(sol.maxProbability(n, edges, succProb, start, end), 0);
}

