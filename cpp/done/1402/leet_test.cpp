#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> satisfaction{-1,-8,0,5,-9};
  EXPECT_EQ(sol.maxSatisfaction(satisfaction), 14);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> satisfaction{4,3,2};
  EXPECT_EQ(sol.maxSatisfaction(satisfaction), 20);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> satisfaction{-1,-4,-5};
  EXPECT_EQ(sol.maxSatisfaction(satisfaction), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> satisfaction{-2,5,-1,0,3,-3};
  EXPECT_EQ(sol.maxSatisfaction(satisfaction), 35);
}

