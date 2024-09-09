#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> cost {1,2,3,4,5};
  EXPECT_EQ(sol.minCost("abaac",cost), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> cost {1,2,3};
  EXPECT_EQ(sol.minCost("abc", cost), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> cost {1,2,3,4,1};
  EXPECT_EQ(sol.minCost("aabaa", cost), 2);
}

