#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 4;
  vector<int> left = {4,3}, right = {0,1};
  EXPECT_EQ(sol.getLastMoment(n, left, right), 4);
}

TEST(kk, t2) {
  Solution sol;
  int n = 7;
  vector<int> left = {}, right = {0,1,2,3,4,5,6,7};
  EXPECT_EQ(sol.getLastMoment(n, left, right), 7);
}

TEST(kk, t3) {
  Solution sol;
  int n = 7;
  vector<int> left = {0,1,2,3,4,5,6,7}, right = {};
  EXPECT_EQ(sol.getLastMoment(n, left, right), 7);
}

TEST(kk, t4) {
  Solution sol;
  int n = 9;
  vector<int> left = {5}, right = {4};
  EXPECT_EQ(sol.getLastMoment(n, left, right), 5);
}

TEST(kk, t5) {
  Solution sol;
  int n = 6;
  vector<int> left = {6}, right = {0};
  EXPECT_EQ(sol.getLastMoment(n, left, right), 6);
}

TEST(kk, t6) {
  Solution sol;
  int n = 20;
  vector<int> left = {9,3,13,10} , right = {4,7,15};
  EXPECT_EQ(sol.getLastMoment(n, left, right), 16);
}

