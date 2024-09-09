#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> destination = {2,3};
  EXPECT_EQ(sol.kthSmallestPath(destination, 1), "HHHVV");
  EXPECT_EQ(sol.kthSmallestPath(destination, 2), "HHVHV");
  EXPECT_EQ(sol.kthSmallestPath(destination, 3), "HHVVH");
}

