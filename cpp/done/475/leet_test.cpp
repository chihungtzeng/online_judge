#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> houses{1,2,3};
  vector<int> heaters{2};

  EXPECT_EQ(sol.findRadius(houses, heaters), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> houses{1,2,3,4};
  vector<int> heaters{1,4};

  EXPECT_EQ(sol.findRadius(houses, heaters), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> houses{1,2,3,4,5};
  vector<int> heaters{2};

  EXPECT_EQ(sol.findRadius(houses, heaters), 3);
}

