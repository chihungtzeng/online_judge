#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
  int sr = 1, sc = 1, newColor = 2;
  vector<vector<int>> expect{{2,2,2},{2,2,0},{2,0,1}};

  EXPECT_EQ(sol.floodFill(image, sr, sc, newColor), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> image = {{0,0,0},{0,1,1}};
  int sr = 1, sc = 1, newColor = 1;
  vector<vector<int>> expect{{0,0,0},{0,1,1}};

  EXPECT_EQ(sol.floodFill(image, sr, sc, newColor), expect);
}


