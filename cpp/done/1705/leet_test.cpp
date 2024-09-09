#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> apples = {1, 2, 3, 5, 2}, days = {3, 2, 1, 4, 2};
  EXPECT_EQ(sol.eatenApples(apples, days), 7);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> apples = {3, 0, 0, 0, 0, 2}, days = {3, 0, 0, 0, 0, 2};
  EXPECT_EQ(sol.eatenApples(apples, days), 5);
}

