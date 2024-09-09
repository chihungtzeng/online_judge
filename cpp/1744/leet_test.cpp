#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> candiesCount = {7, 4, 5, 3, 8};
  vector<vector<int>> queries = {{0, 2, 2}, {4, 2, 4}, {2, 13, 1000000000}};
  vector<bool> expect{true, false, true};
  EXPECT_EQ(sol.canEat(candiesCount, queries), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> candiesCount = {5, 2, 6, 4, 1};
  vector<vector<int>> queries = {
      {3, 1, 2}, {4, 10, 3}, {3, 10, 100}, {4, 100, 30}, {1, 3, 1}};
  vector<bool> expect{false, true, true, false, false};
  EXPECT_EQ(sol.canEat(candiesCount, queries), expect);
}

