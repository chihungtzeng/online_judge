#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int m = 2, n = 3, introvertsCount = 1, extrovertsCount = 2;
  EXPECT_EQ(sol.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount),
            240);
}

TEST(kk, t2) {
  Solution sol;
  int m = 3, n = 1, introvertsCount = 2, extrovertsCount = 1;
  EXPECT_EQ(sol.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount),
            260);
}

TEST(kk, t3) {
  Solution sol;
  int m = 2, n = 2, introvertsCount = 4, extrovertsCount = 0;
  EXPECT_EQ(sol.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount),
            240);
}

TEST(kk, t4) {
  Solution sol;
  int m = 5, n = 4, introvertsCount = 6, extrovertsCount = 3;
  EXPECT_EQ(sol.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount),
            240);
}

