#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> flowerbed{1,0,0,0,1};

  EXPECT_EQ(sol.canPlaceFlowers(flowerbed, 1), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> flowerbed{1,0,0,0,1};

  EXPECT_EQ(sol.canPlaceFlowers(flowerbed, 2), false);
}

