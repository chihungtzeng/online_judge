#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> bloomDay = {1,10,3,10,2};
  int m = 3, k = 1;
  EXPECT_EQ(sol.minDays(bloomDay, m, k), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> bloomDay = {1,10,3,10,2};
  int m = 3, k = 2;
  EXPECT_EQ(sol.minDays(bloomDay, m, k), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> bloomDay = {7,7,7,7,12,7,7};
  int m = 2, k = 3;
  EXPECT_EQ(sol.minDays(bloomDay, m, k), 12);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> bloomDay = {1000000000, 1000000000};
  int m = 1, k = 1;
  EXPECT_EQ(sol.minDays(bloomDay, m, k), 1000000000);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> bloomDay = {1,10,2,9,3,8,4,7,5,6};
  int m = 4, k = 2;
  EXPECT_EQ(sol.minDays(bloomDay, m, k), 9);
}

