#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 2;
  vector<vector<int>> prerequisites = {{1, 0}}, queries = {{0, 1}, {1, 0}};
  vector<bool> expect{false, true};
  EXPECT_EQ(sol.checkIfPrerequisite(n, prerequisites, queries), expect);
}

TEST(kk, t2) {
  Solution sol;
  int n = 2;
  vector<vector<int>> prerequisites = {}, queries = {{1, 0}, {0, 1}};
  vector<bool> expect{false, false};
  EXPECT_EQ(sol.checkIfPrerequisite(n, prerequisites, queries), expect);
}
TEST(kk, t3) {
  Solution sol;
  int n = 3;
  vector<vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}},
                      queries = {{1, 0}, {1, 2}};
  vector<bool> expect{true, true};
  EXPECT_EQ(sol.checkIfPrerequisite(n, prerequisites, queries), expect);
}

TEST(kk, t4) {
  Solution sol;
  int n = 3;
  vector<vector<int>> prerequisites = {{1, 0}, {2, 0}},
                      queries = {{0, 1}, {2, 0}};
  vector<bool> expect{false, true};
  EXPECT_EQ(sol.checkIfPrerequisite(n, prerequisites, queries), expect);
}

TEST(kk, t5) {
  Solution sol;
  int n = 5;
  vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 3}, {3, 4}},
                      queries = {{0, 4}, {4, 0}, {1, 3}, {3, 0}};
  vector<bool> expect{true, false, true, false};
  EXPECT_EQ(sol.checkIfPrerequisite(n, prerequisites, queries), expect);
}

