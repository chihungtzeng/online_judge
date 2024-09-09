#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 4;
  vector<int> rounds = {1,3,1,2};
  vector<int> expect{1,2};

  EXPECT_EQ(sol.mostVisited(n, rounds), expect);
}

TEST(kk, t2) {
  Solution sol;
  int n = 2;
  vector<int> rounds = {2,1,2,1,2,1,2,1,2};
  vector<int> expect{2};

  EXPECT_EQ(sol.mostVisited(n, rounds), expect);
}

TEST(kk, t3) {
  Solution sol;
  int n = 7;
  vector<int> rounds = {1,3,5,7};
  vector<int> expect{1,2,3,4,5,6,7};

  EXPECT_EQ(sol.mostVisited(n, rounds), expect);
}

