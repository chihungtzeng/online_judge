#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 2;
  vector<vector<int>> languages = {{1}, {2}, {1, 2}},
                      friendships = {{1, 2}, {1, 3}, {2, 3}};
  EXPECT_EQ(sol.minimumTeachings(n, languages, friendships), 1);
}

TEST(kk, t2) {
  Solution sol;
  int n = 3;
  vector<vector<int>> languages = {{2}, {1, 3}, {1, 2}, {3}},
                      friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
  EXPECT_EQ(sol.minimumTeachings(n, languages, friendships), 2);
}

