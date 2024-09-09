#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> row{0, 2, 1, 3};

  EXPECT_EQ(sol.minSwapsCouples(row), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> row{3, 2, 0, 1};

  EXPECT_EQ(sol.minSwapsCouples(row), 0);
}

