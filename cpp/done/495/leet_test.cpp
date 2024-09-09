#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t2) {
  Solution sol;
  vector<int> ts{1,4};

  EXPECT_EQ(sol.findPoisonedDuration(ts, 2), 4);
  vector<int> ts2{1,2};
  EXPECT_EQ(sol.findPoisonedDuration(ts2, 2), 3);
}

