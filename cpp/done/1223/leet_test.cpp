#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 2;
  vector<int> rollMax = {1, 1, 2, 2, 2, 3};
  EXPECT_EQ(sol.dieSimulator(n, rollMax), 34);
}

TEST(kk, t2) {
  Solution sol;
  int n = 2;
  vector<int> rollMax = {1, 1, 1, 1, 1, 1};
  EXPECT_EQ(sol.dieSimulator(n, rollMax), 30);
}

TEST(kk, t3) {
  Solution sol;
  int n = 3;
  vector<int> rollMax = {1, 1, 1, 2, 2, 3};
  EXPECT_EQ(sol.dieSimulator(n, rollMax), 181);
}

TEST(kk, t4) {
  Solution sol;
  int n = 5000;
  vector<int> rollMax = {1, 3, 5, 7, 11, 13};
  EXPECT_EQ(sol.dieSimulator(n, rollMax), 778640190);
}

