#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> A = {4, 7, 9, 10};
  int K = 1;
  EXPECT_EQ(sol.missingElement(A, K), 5);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> A = {4, 7, 9, 10};
  int K = 3;
  EXPECT_EQ(sol.missingElement(A, K), 8);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> A = {1, 2, 4};
  int K = 3;
  EXPECT_EQ(sol.missingElement(A, K), 6);
}

