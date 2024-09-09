#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  int n = 4;
  vector<vector<int>> dislikes = { { 1, 2 }, { 1, 3 }, { 2, 4 } };
  EXPECT_EQ(sol.possibleBipartition(n, dislikes), true);
}

TEST(kk, t2)
{
  Solution sol;
  int n = 3;
  vector<vector<int>> dislikes = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
  EXPECT_EQ(sol.possibleBipartition(n, dislikes), false);
}

TEST(kk, t3)
{
  Solution sol;
  int n = 5;
  vector<vector<int>> dislikes = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 1, 5 } };
  EXPECT_EQ(sol.possibleBipartition(n, dislikes), false);
}

