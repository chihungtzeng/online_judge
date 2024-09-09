#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
  EXPECT_EQ(sol.maxHeight(cuboids), 190);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> cuboids = {{38, 25, 45}, {76, 35, 3}};
  EXPECT_EQ(sol.maxHeight(cuboids), 76);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> cuboids = {{7, 11, 17}, {7, 17, 11}, {11, 7, 17},
                                 {11, 17, 7}, {17, 7, 11}, {17, 11, 7}};
  EXPECT_EQ(sol.maxHeight(cuboids), 102);
}

