#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> svals{6,2,3,4,5,5};
  EXPECT_EQ(sol.stoneGameV(svals), 18);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> svals{7,7,7,7,7,7,7};
  EXPECT_EQ(sol.stoneGameV(svals), 28);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> svals{4};
  EXPECT_EQ(sol.stoneGameV(svals), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> svals{3,1,4,1,5,9,2,6,2,7,1,8,2,8};
  EXPECT_EQ(sol.stoneGameV(svals), 40);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> svals{68,75,25,50,34,29,77,1,2,69};
  EXPECT_EQ(sol.stoneGameV(svals), 304);
}

