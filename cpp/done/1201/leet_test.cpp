#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t0) {
  Solution sol;
  int n = 1, a = 2, b = 3, c = 5;
  EXPECT_EQ(sol.nthUglyNumber(n, a, b, c), 2);
}


TEST(kk, t1) {
  Solution sol;
  int n = 3, a = 2, b = 3, c = 5;
  EXPECT_EQ(sol.nthUglyNumber(n, a, b, c), 4);
}

TEST(kk, t2) {
  Solution sol;
  int n = 4, a = 2, b = 3, c = 4;
  EXPECT_EQ(sol.nthUglyNumber(n, a, b, c), 6);
}

TEST(kk, t3) {
  Solution sol;
  int n = 5, a = 2, b = 11, c = 13;
  EXPECT_EQ(sol.nthUglyNumber(n, a, b, c), 10);
}

TEST(kk, t4) {
  Solution sol;
  int n = 1000000000, a = 2, b = 217983653, c = 336916467;
  EXPECT_EQ(sol.nthUglyNumber(n, a, b, c), 1999999984);
}

// shit
TEST(kk, t5) {
  Solution sol;
  int n = 5, a = 2, b = 3, c = 3;
  EXPECT_EQ(sol.nthUglyNumber(n, a, b, c), 8);
}

TEST(kk, t6) {
  Solution sol;
  int n = 7, a = 7, b = 7, c = 7;
  EXPECT_EQ(sol.nthUglyNumber(n, a, b, c), 49);
}

TEST(kk, t7) {
  Solution sol;
  int n = 27, a = 16, b = 22, c = 11;
  EXPECT_EQ(sol.nthUglyNumber(n, a, b, c), 187);
}

