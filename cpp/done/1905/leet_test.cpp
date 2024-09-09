#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  vector<vector<int>> grid1 = {{1, 1, 1, 0, 0},
                               {0, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 1, 1}},
                      grid2 = {{1, 1, 1, 0, 0},
                               {0, 0, 1, 1, 1},
                               {0, 1, 0, 0, 0},
                               {1, 0, 1, 1, 0},
                               {0, 1, 0, 1, 0}};
  EXPECT_EQ(sol.countSubIslands(grid1, grid2), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid1 = {{1, 0, 1, 0, 1},
                               {1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0},
                               {1, 1, 1, 1, 1},
                               {1, 0, 1, 0, 1}},
                      grid2 = {{0, 0, 0, 0, 0},
                               {1, 1, 1, 1, 1},
                               {0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0},
                               {1, 0, 0, 0, 1}};
  EXPECT_EQ(sol.countSubIslands(grid1, grid2), 2);
}

