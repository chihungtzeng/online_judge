#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> times{{2,1,1},{2,3,1},{3,4,1}};
  int N = 4, K = 2;

  EXPECT_EQ(sol.networkDelayTime(times, N, K), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> times{{1,2,1}, {2,3,1}};
  int N = 3, K = 2;

  EXPECT_EQ(sol.networkDelayTime(times, N, K), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> times{{1,2,1}, {2,3,4}};
  int N = 3, K = 1;

  EXPECT_EQ(sol.networkDelayTime(times, N, K), 5);
}


