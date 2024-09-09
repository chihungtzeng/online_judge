#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> p1 = {0,0}, p2 = {1,1}, p3 = {1,0}, p4 = {0,1};

  EXPECT_EQ(sol.validSquare(p1, p2, p3, p4), true);
}


TEST(kk, t2) {
  Solution sol;
  vector<int> p1 = {0,-1}, p2 = {1,1}, p3 = {1,0}, p4 = {0,1};

  EXPECT_EQ(sol.validSquare(p1, p2, p3, p4), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> p1 = {-10000,-10000}, p2 = {10000,10000}, p3 = {10000,-10000}, p4 = {-10000,10000};

  EXPECT_EQ(sol.validSquare(p1, p2, p3, p4), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> p1 = {0,0}, p2 = {0,0}, p3 = {0,0}, p4 = {0,0};

  EXPECT_EQ(sol.validSquare(p1, p2, p3, p4), false);
}


