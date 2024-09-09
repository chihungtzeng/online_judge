#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<char> tasks{'A','A','A','B','B','B'};
  int n = 2;

  EXPECT_EQ(sol.leastInterval(tasks, n), 8);
}

TEST(kk, t2) {
  Solution sol;
  vector<char> tasks {'A','A','A','B','B','B'};
  int n = 0;

  EXPECT_EQ(sol.leastInterval(tasks, n), 6);
}

TEST(kk, t3) {
  Solution sol;
  vector<char> tasks{'A','A','A','A','A','A','B','C','D','E','F','G'};
  int n = 2;

  EXPECT_EQ(sol.leastInterval(tasks, n), 16);
}

TEST(kk, t4) {

  Solution sol;
  vector<char> tasks{'A','A','A','B','B','B'};
  int n = 50;

  EXPECT_EQ(sol.leastInterval(tasks, n), 104);
}


