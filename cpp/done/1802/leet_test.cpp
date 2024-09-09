#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

constexpr int b = 1e9;
TEST(kk, t1) {
  Solution sol;
  int n = 6, index = 1,  maxSum = 10;
  EXPECT_EQ(sol.maxValue(n, index, maxSum), 3);
}

TEST(kk, t2) {
  Solution sol;
  int n = 4, index = 2,  maxSum = 6;
  EXPECT_EQ(sol.maxValue(n, index, maxSum), 2);
}

TEST(kk, t3) {
  Solution sol;
  int n = b, index = b-1,  maxSum = b;
  EXPECT_EQ(sol.maxValue(n, index, maxSum), 1);
}

TEST(kk, t4) {
  Solution sol;
  int n = 1, index = 0,  maxSum = b;
  EXPECT_EQ(sol.maxValue(n, index, maxSum), b);
}

TEST(kk, t5) {
  Solution sol;
  int n = 9, index = 5,  maxSum = 24;
  EXPECT_EQ(sol.maxValue(n, index, maxSum), 4);
}

TEST(kk, t6) {
  Solution sol;
  int n = b, index = b/10,  maxSum = b;
  EXPECT_EQ(sol.maxValue(n, index, maxSum), 1);
}


