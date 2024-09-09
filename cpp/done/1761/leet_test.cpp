#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 6;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}};
  EXPECT_EQ(sol.minTrioDegree(n, edges), 3);
}

TEST(kk, t2) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges = {{1, 3}, {4, 1}, {4, 3}, {2, 5},
                               {5, 6}, {6, 7}, {7, 5}, {2, 6}};
  EXPECT_EQ(sol.minTrioDegree(n, edges), 0);
}

TEST(kk, t3) {
  Solution sol;
  int n = 400;
  vector<vector<int>> edges;
  for(int u=1; u<=n; u++){
    for(int v=u+1; v<=n; v++){
      edges.push_back(vector<int>{u, v});
    }
  }
  EXPECT_EQ(sol.minTrioDegree(n, edges), (n-1)*3 - 6);
}

