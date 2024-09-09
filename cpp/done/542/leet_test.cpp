#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> matrix{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> expect{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  EXPECT_EQ(sol.updateMatrix(matrix), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> matrix{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  vector<vector<int>> expect{{0, 0, 0}, {0, 1, 0}, {1, 2, 1}};

  EXPECT_EQ(sol.updateMatrix(matrix), expect);
}

