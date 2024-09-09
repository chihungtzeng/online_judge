#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> points = {{2, 1}, {2, 2}, {3, 3}};
  int angle = 90;
  vector<int> location = {1, 1};
  EXPECT_EQ(sol.visiblePoints(points, angle, location), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> points = {{2, 1}, {2, 2}, {3, 4}, {1, 1}};
  int angle = 90;
  vector<int> location = {1, 1};
  EXPECT_EQ(sol.visiblePoints(points, angle, location), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> points = {{1, 0}, {2, 1}};
  int angle = 13;
  vector<int> location = {1, 1};
  EXPECT_EQ(sol.visiblePoints(points, angle, location), 1);
}

