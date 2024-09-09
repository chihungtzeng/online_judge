#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> A{0,6,5,2,2,5,1,9,4};
  int L = 1, M = 2;

  EXPECT_EQ(sol.maxSumTwoNoOverlap(A, L, M), 20);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> A{3,8,1,3,2,1,8,9,0};
  int L = 3, M = 2;

  EXPECT_EQ(sol.maxSumTwoNoOverlap(A, L, M), 29);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> A{2,1,5,6,0,9,5,0,3,8};
  int L = 4, M = 3;

  EXPECT_EQ(sol.maxSumTwoNoOverlap(A, L, M), 31);
}

