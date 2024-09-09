#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int upper = 2, lower = 1;
  vector<int> colsum = {1, 1, 1};
  auto actual = sol.reconstructMatrix(upper, lower, colsum);
  for (int i = 0; i < colsum.size(); i++) {
    EXPECT_EQ(actual[0][i] + actual[1][i], colsum[i]);
  }
  EXPECT_EQ(accumulate(actual[0].begin(), actual[0].end(), 0), upper);
  EXPECT_EQ(accumulate(actual[1].begin(), actual[1].end(), 0), lower);
}

TEST(kk, t2) {
  Solution sol;
  int upper = 2, lower = 3;
  vector<int> colsum = {2, 2, 1, 1};
  auto actual = sol.reconstructMatrix(upper, lower, colsum);
  EXPECT_EQ(actual.size(), 0);
}

TEST(kk, t3) {
  Solution sol;
  int upper = 5, lower = 5;
  vector<int> colsum = {2, 1, 2, 0, 1, 0, 1, 2, 0, 1};
  auto actual = sol.reconstructMatrix(upper, lower, colsum);
  for (int i = 0; i < colsum.size(); i++) {
    EXPECT_EQ(actual[0][i] + actual[1][i], colsum[i]);
  }
  EXPECT_EQ(accumulate(actual[0].begin(), actual[0].end(), 0), upper);
  EXPECT_EQ(accumulate(actual[1].begin(), actual[1].end(), 0), lower);
}

TEST(kk, t4) {
  Solution sol;
  int upper = 1, lower = 4;
  vector<int> colsum = {2, 1, 2, 0, 0, 2};
  auto actual = sol.reconstructMatrix(upper, lower, colsum);
  EXPECT_EQ(actual.size(), 0);
}

TEST(kk, t5) {
  Solution sol;
  int upper = 4, lower = 7;
  vector<int> colsum = {2, 1, 2, 2, 1, 1, 1};
  auto actual = sol.reconstructMatrix(upper, lower, colsum);
  EXPECT_EQ(actual.size(), 0);
}

