#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<char>> grid = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};

  EXPECT_EQ(sol.containsCycle(grid), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<char>> grid {{'a','b','b'},{'b','z','b'},{'b','b','a'}};

  EXPECT_EQ(sol.containsCycle(grid), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<char>> grid {{'b','a','c'},{'c','a','c'},{'d','d','c'},{'b','c','c'}};

  EXPECT_EQ(sol.containsCycle(grid), false);
}

