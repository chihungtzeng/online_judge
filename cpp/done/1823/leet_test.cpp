#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 5, k = 2;
  EXPECT_EQ(sol.findTheWinner(n, k), 3);
}

TEST(kk, t2) {
  Solution sol;
  int n = 6, k = 5;
  EXPECT_EQ(sol.findTheWinner(n, k), 1);
}

TEST(kk, t3) {
  Solution sol;
  int n = 500, k = 500;
  EXPECT_EQ(sol.findTheWinner(n, k), 69);
}

