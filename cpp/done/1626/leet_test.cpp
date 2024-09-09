#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> scores = {1, 3, 5, 10, 15}, ages = {1, 2, 3, 4, 5};
  EXPECT_EQ(sol.bestTeamScore(scores, ages), 34);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> scores = {4, 5, 6, 5}, ages = {2, 1, 2, 1};
  EXPECT_EQ(sol.bestTeamScore(scores, ages), 16);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> scores = {1, 2, 3, 5}, ages = {8, 9, 10, 1};
  EXPECT_EQ(sol.bestTeamScore(scores, ages), 6);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> scores = {9, 2, 8, 8, 2}, ages = {4, 1, 3, 3, 5};
  EXPECT_EQ(sol.bestTeamScore(scores, ages), 27);
}

