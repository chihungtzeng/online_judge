#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> matrix{{1, 2, 2, 3, 5},
                             {3, 2, 3, 4, 4},
                             {2, 4, 5, 3, 1},
                             {6, 7, 1, 4, 5},
                             {5, 1, 1, 2, 4}};
  vector<vector<int>> expect{{0, 4}, {1, 3}, {1, 4}, {2, 2},
                             {3, 0}, {3, 1}, {4, 0}};

  EXPECT_EQ(sol.pacificAtlantic(matrix), expect);
}

