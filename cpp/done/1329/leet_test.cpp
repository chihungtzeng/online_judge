#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
  vector<vector<int>> expect =  {{1,1,1,1},{1,2,2,2},{1,2,3,3}};

  EXPECT_EQ(sol.diagonalSort(mat), expect);
}

