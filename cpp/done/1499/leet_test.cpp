#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> points{{1,3},{2,0},{5,10},{6,-10}};
  EXPECT_EQ(sol.findMaxValueOfEquation(points, 1), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> points{{0,0},{3,0},{9,2}};
  EXPECT_EQ(sol.findMaxValueOfEquation(points, 3), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> points {{-19,-12},{-13,-18},{-12,18},{-11,-8},{-8,2},{-7,12},{-5,16},{-3,9},{1,-7},{5,-4},{6,-20},{10,4},{16,4},{19,-9},{20,19}};
  EXPECT_EQ(sol.findMaxValueOfEquation(points, 6), 35);
}


