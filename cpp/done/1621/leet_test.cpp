#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 4, k = 2;
  EXPECT_EQ(sol.numberOfSets(n, k), 5);
}

TEST(kk, t2) {
  Solution sol;
  int n = 3, k = 1;
  EXPECT_EQ(sol.numberOfSets(n, k), 3);
}

TEST(kk, t3) {
  Solution sol;
  int n = 30, k = 7;
  EXPECT_EQ(sol.numberOfSets(n, k), 796297179);
}

TEST(kk, t4) {
  Solution sol;
  int n = 5, k = 3;
  EXPECT_EQ(sol.numberOfSets(n, k), 7);
}

TEST(kk, t5) {
  Solution sol;
  int n = 3, k = 2;
  EXPECT_EQ(sol.numberOfSets(n, k), 1);
}

TEST(kk, t6) {
  Solution sol;
  int n = 1000, k = 500;
  EXPECT_EQ(sol.numberOfSets(n, k), 70047606);
}

