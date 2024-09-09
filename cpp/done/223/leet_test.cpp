#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;

  EXPECT_EQ(sol.computeArea(A, B, C, D, E, F, G, H), 45);
}

TEST(kk, o1) {
  Solution sol;
  Seg s1{-3,3};
  Seg s2{0,9};
  Seg exp{0,3};

  EXPECT_EQ(sol.overlap(s1, s2), exp);
}

