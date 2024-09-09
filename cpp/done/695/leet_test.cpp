#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

  EXPECT_EQ(sol.maxAreaOfIsland(grid), 6);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid{{0, 0, 0, 0, 0, 0, 0, 0}};

  EXPECT_EQ(sol.maxAreaOfIsland(grid), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid{{0, 1, 1, 0, 1, 1, 1, 0},
                           {1, 1, 1, 0, 0, 0, 1, 0}};

  EXPECT_EQ(sol.maxAreaOfIsland(grid), 5);
}

