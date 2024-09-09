#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> vs{1,2,3,7};
  EXPECT_EQ(sol.stoneGameIII(vs), "Bob");
}

TEST(kk, t2) {
  Solution sol;
  vector<int> vs{1,2,3,-9};
  EXPECT_EQ(sol.stoneGameIII(vs), "Alice");
}

TEST(kk, t5) {
  Solution sol;
  vector<int> vs{1,2,3,6};
  EXPECT_EQ(sol.stoneGameIII(vs), "Tie");
}

TEST(kk, t3) {
  Solution sol;
  vector<int> vs{1,2,3,-1,-2,-3,7};
  EXPECT_EQ(sol.stoneGameIII(vs), "Alice");
}

TEST(kk, t4) {
  Solution sol;
  vector<int> vs{-1,-2,-3};
  EXPECT_EQ(sol.stoneGameIII(vs), "Tie");
}

