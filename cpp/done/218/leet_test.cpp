#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> buildings{
      {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  vector<vector<int>> expect{{2, 10},  {3, 15}, {7, 12}, {12, 0},
                             {15, 10}, {20, 8}, {24, 0}};

  EXPECT_EQ(sol.getSkyline(buildings), expect);
}

