#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> tps{"23:59","00:00"};

  EXPECT_EQ(sol.findMinDifference(tps), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> tps{"10:30","8:40", "9:20", "23:05"};

  EXPECT_EQ(sol.findMinDifference(tps), 40);
}

