#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> rating = {2, 5, 3, 4, 1};
  EXPECT_EQ(sol.numTeams(rating), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> rating = {2, 1, 3};
  EXPECT_EQ(sol.numTeams(rating), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> rating = {1, 2, 3, 4};
  EXPECT_EQ(sol.numTeams(rating), 4);
}

