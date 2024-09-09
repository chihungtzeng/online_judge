#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  std::vector<int> A{4, 3, 2, 6};
  std::vector<int> B;
  std::vector<int> C{5};

  EXPECT_EQ(sol.maxRotateFunction(A), 26);
  EXPECT_EQ(sol.maxRotateFunction(B), 0);
  EXPECT_EQ(sol.maxRotateFunction(C), 0);
}

TEST(kk, t2) {
  Solution sol;
  std::vector<int> A(10000);
  for(int i=0; i<10000; i++){
    A[i] = (i + 2) % 10;
  }

  EXPECT_EQ(sol.maxRotateFunction(A), 225060000);
}

TEST(kk, t3) {
  Solution sol;
  std::vector<int> A{2147483647,2147483647};

  EXPECT_EQ(sol.maxRotateFunction(A), 2147483647);
}


