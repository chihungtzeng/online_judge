#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> values = {5, 4, 3, 2, 1}, labels = {1, 1, 2, 2, 3};
  int num_wanted = 3, use_limit = 1;
  EXPECT_EQ(sol.largestValsFromLabels(values, labels, num_wanted, use_limit),
            9);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> values = {5, 4, 3, 2, 1}, labels = {1, 3, 3, 3, 2};
  int num_wanted = 3, use_limit = 2;
  EXPECT_EQ(sol.largestValsFromLabels(values, labels, num_wanted, use_limit),
            12);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> values = {9, 8, 8, 7, 6}, labels = {0, 0, 0, 1, 1};
  int num_wanted = 3, use_limit = 1;
  EXPECT_EQ(sol.largestValsFromLabels(values, labels, num_wanted, use_limit),
            16);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> values = {9, 8, 8, 7, 6}, labels = {0, 0, 0, 1, 1};
  int num_wanted = 3, use_limit = 2;
  EXPECT_EQ(sol.largestValsFromLabels(values, labels, num_wanted, use_limit),
            24);
}

