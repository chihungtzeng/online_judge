#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> cuts{1, 3, 4, 5};
  EXPECT_EQ(sol.minCost(7, cuts), 16);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> cuts{5, 6, 1, 4, 2};
  EXPECT_EQ(sol.minCost(9, cuts), 22);
}

