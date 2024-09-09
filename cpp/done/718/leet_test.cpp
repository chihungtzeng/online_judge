#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> A{1, 2, 3, 2, 1};
  vector<int> B{3, 2, 1, 4, 7};

  EXPECT_EQ(sol.findLength(A, B), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> A{1, 2, 3, 2, 1, 4, 9};
  vector<int> B{5, 3, 2, 1, 4, 7};

  EXPECT_EQ(sol.findLength(A, B), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> A{0, 1, 1, 1, 1};
  vector<int> B{1, 0, 1, 0, 1};

  EXPECT_EQ(sol.findLength(A, B), 2);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> A {1,0,0,0,1};
  vector<int> B {1,0,0,1,1};

  EXPECT_EQ(sol.findLength(A, B), 3);
}

