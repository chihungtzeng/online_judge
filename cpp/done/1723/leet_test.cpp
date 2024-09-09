#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> jobs = {3, 2, 3};
  int k = 3;
  EXPECT_EQ(sol.minimumTimeRequired(jobs, k), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> jobs = {1, 2, 4, 7, 8};
  int k = 2;
  EXPECT_EQ(sol.minimumTimeRequired(jobs, k), 11);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> jobs = {38, 49, 91, 59, 14, 76, 84};
  int k = 3;
  EXPECT_EQ(sol.minimumTimeRequired(jobs, k), 140);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> jobs = {11, 2, 20, 18, 2, 1, 7, 11, 7, 10};
  int k = 9;
  EXPECT_EQ(sol.minimumTimeRequired(jobs, k), 20);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> jobs = {302, 202, 108, 477, 351, 273,
                      356, 668, 858, 917, 935, 640};
  int k = 5;
  EXPECT_EQ(sol.minimumTimeRequired(jobs, k), 1225);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> jobs = {254,256,256,254,251,256,254,253,255,251,251,255};
  int k = 10;
  EXPECT_EQ(sol.minimumTimeRequired(jobs, k), 504);
}

