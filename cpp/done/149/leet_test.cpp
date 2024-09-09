#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> points{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
  EXPECT_EQ(sol.maxPoints(points), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> points0;
  vector<vector<int>> points1{{1,1}};
  vector<vector<int>> points2{{1,1}, {2,3}};
  EXPECT_EQ(sol.maxPoints(points0), 0);
  EXPECT_EQ(sol.maxPoints(points1), 1);
  EXPECT_EQ(sol.maxPoints(points2), 2);
}



TEST(kk, g1) {
  Solution sol;
  EXPECT_EQ(sol.gcd(18, 12), 6);
  EXPECT_EQ(sol.gcd(18, 16), 2);
  EXPECT_EQ(sol.gcd(100, 25), 25);
}

