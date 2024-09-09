#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kerker, t1) {
  Solution sol;

  vector<vector<int>> dungeon{{-2, -3,3}, {-5, -10, 1}, {10,30,-5}};
  EXPECT_EQ(sol.calculateMinimumHP(dungeon), 7);
}

