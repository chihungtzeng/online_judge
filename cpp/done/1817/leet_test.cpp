#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> logs = {{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
  int k = 5;
  vector<int> expect{0, 2, 0, 0, 0};
  EXPECT_EQ(sol.findingUsersActiveMinutes(logs, k), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> logs = {{1, 1}, {2, 2}, {2, 3}};
  int k = 4;
  vector<int> expect{1, 1, 0, 0};
  EXPECT_EQ(sol.findingUsersActiveMinutes(logs, k), expect);
}

