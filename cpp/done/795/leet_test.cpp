#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> A{2, 1, 4, 3};
  int L = 2;
  int R = 3;

  EXPECT_EQ(sol.numSubarrayBoundedMax(A, L, R), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> A{2,3,4,2,0,1};
  int L = 2;
  int R = 3;

  EXPECT_EQ(sol.numSubarrayBoundedMax(A, L, R), 6);
}

