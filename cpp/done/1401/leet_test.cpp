#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1;
  EXPECT_EQ(sol.checkOverlap(radius, x_center, y_center, x1, y1,x2, y2), true);
}

TEST(kk, t2) {
  Solution sol;
  int radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1;
  EXPECT_EQ(sol.checkOverlap(radius, x_center, y_center, x1, y1,x2, y2), true);
}

TEST(kk, t3) {
  Solution sol;
  int  radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3;
  EXPECT_EQ(sol.checkOverlap(radius, x_center, y_center, x1, y1,x2, y2), true);
}

TEST(kk, t4) {
  Solution sol;
  int radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1;
  EXPECT_EQ(sol.checkOverlap(radius, x_center, y_center, x1, y1,x2, y2), false);
}

