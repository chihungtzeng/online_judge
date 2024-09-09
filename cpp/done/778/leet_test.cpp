#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid{{0, 2}, {1, 3}};

  EXPECT_EQ(sol.swimInWater(grid), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid{{0, 1, 2, 3, 4},
                           {24, 23, 22, 21, 5},
                           {12, 13, 14, 15, 16},
                           {11, 17, 18, 19, 20},
                           {10, 9, 8, 7, 6}};

  EXPECT_EQ(sol.swimInWater(grid), 16);
}

