#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> ps{1,2,3,4,5,6,1};
  EXPECT_EQ(sol.maxScore(ps, 3), 12);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> ps{2,2,2};
  EXPECT_EQ(sol.maxScore(ps, 2), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> ps{9,7,7,9,7,7,9};
  EXPECT_EQ(sol.maxScore(ps, 7), 55);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> ps{1,1000,1};
  EXPECT_EQ(sol.maxScore(ps, 1), 1);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> ps{1,79,80,1,1,1,200,1};
  EXPECT_EQ(sol.maxScore(ps, 3), 202);
}

