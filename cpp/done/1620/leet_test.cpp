#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> towers = {{1, 2, 5}, {2, 1, 7}, {3, 1, 9}};
  int radius = 2;
  vector<int> expect{2, 1};
  EXPECT_EQ(sol.bestCoordinate(towers, radius), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> towers = {{23, 11, 21}};
  int radius = 9;
  vector<int> expect{23, 11};
  EXPECT_EQ(sol.bestCoordinate(towers, radius), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> towers = {{1, 2, 13}, {2, 1, 7}, {0, 1, 9}};
  int radius = 2;
  vector<int> expect{1, 2};
  EXPECT_EQ(sol.bestCoordinate(towers, radius), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> towers = {{2, 1, 9}, {0, 1, 9}};
  int radius = 2;
  vector<int> expect{0, 1};
  EXPECT_EQ(sol.bestCoordinate(towers, radius), expect);
}

