#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> coins{1, 2, 5};

  EXPECT_EQ(sol.change(5, coins), 4);
  EXPECT_EQ(sol.change(0, coins), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> coins{2};

  EXPECT_EQ(sol.change(3, coins), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> coins{10};

  EXPECT_EQ(sol.change(10, coins), 1);
}

