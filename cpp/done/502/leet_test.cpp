#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int k=2, W=0;
  vector<int> Profits{1,2,3}, Capital{0,1,1};

  EXPECT_EQ(sol.findMaximizedCapital(k, W, Profits, Capital), 4);
}

