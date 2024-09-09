#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> deliciousness = {1,3,5,7,9};
  EXPECT_EQ(sol.countPairs(deliciousness), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> deliciousness = {1,1,1,3,3,3,7};
  EXPECT_EQ(sol.countPairs(deliciousness), 15);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> deliciousness = {1,1,1,3,3,3,7, 0, 0, 2,2,2,2,2};
  EXPECT_EQ(sol.countPairs(deliciousness), 41);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> deliciousness(100000,32);
  EXPECT_EQ(sol.countPairs(deliciousness), 999949972);
}

