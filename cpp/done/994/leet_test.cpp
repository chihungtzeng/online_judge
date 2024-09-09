#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  EXPECT_EQ(sol.orangesRotting(grid), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};

  EXPECT_EQ(sol.orangesRotting(grid), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid{{0, 2}};

  EXPECT_EQ(sol.orangesRotting(grid), 0);
}

