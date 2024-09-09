#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
  string labels = "abaedcd";
  vector<int> expect{2, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(sol.countSubTrees(n, edges, labels), expect);
}

TEST(kk, t2) {
  Solution sol;
  int n = 4;
  vector<vector<int>> edges{{0, 1}, {1, 2}, {0, 3}};
  string labels = "bbbb";
  vector<int> expect{4, 2, 1, 1};
  EXPECT_EQ(sol.countSubTrees(n, edges, labels), expect);
}

TEST(kk, t3) {
  Solution sol;
  int n = 5;
  vector<vector<int>> edges{{0, 1}, {0, 2}, {1, 3}, {0, 4}};
  string labels = "aabab";
  vector<int> expect{3, 2, 1, 1, 1};
  EXPECT_EQ(sol.countSubTrees(n, edges, labels), expect);
}

TEST(kk, t4) {
  Solution sol;
  int n = 6;
  vector<vector<int>> edges{{0, 1}, {0, 2}, {1, 3}, {3, 4}, {4, 5}};
  string labels = "cbabaa";
  vector<int> expect{1, 2, 1, 1, 2, 1};
  EXPECT_EQ(sol.countSubTrees(n, edges, labels), expect);
}

TEST(kk, t5) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
  string labels = "aaabaaa";
  vector<int> expect{6, 5, 4, 1, 3, 2, 1};
  EXPECT_EQ(sol.countSubTrees(n, edges, labels), expect);
}

TEST(kk, t6) {
  Solution sol;
  int n = 4;
  vector<vector<int>> edges{{0, 2}, {0, 3}, {1, 2}};
  string labels = "aeed";
  vector<int> expect{1,1,2,1};
  EXPECT_EQ(sol.countSubTrees(n, edges, labels), expect);
}

