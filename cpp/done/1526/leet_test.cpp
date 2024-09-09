#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> target{3,1,5,4,2};

  EXPECT_EQ(sol.minNumberOperations(target), 7);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> target{1,1,1,1};

  EXPECT_EQ(sol.minNumberOperations(target), 1);
}

