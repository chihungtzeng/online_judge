#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> rectangles = {
      {1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};

  EXPECT_EQ(sol.isRectangleCover(rectangles), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> rectangles{
      {1, 1, 2, 3}, {1, 3, 2, 4}, {3, 1, 4, 2}, {3, 2, 4, 4}};

  EXPECT_EQ(sol.isRectangleCover(rectangles), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> rectangles{
      {1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {3, 2, 4, 4}};

  EXPECT_EQ(sol.isRectangleCover(rectangles), false);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> rectangles{
      {1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {2, 2, 4, 4}};

  EXPECT_EQ(sol.isRectangleCover(rectangles), false);
}

