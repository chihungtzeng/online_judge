#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> obstacles = {0, 1, 2, 3, 0};
  EXPECT_EQ(sol.minSideJumps(obstacles), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> obstacles = {0, 1, 1, 3, 3, 0};
  EXPECT_EQ(sol.minSideJumps(obstacles), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> obstacles = {0, 2, 1, 0, 3, 0};
  EXPECT_EQ(sol.minSideJumps(obstacles), 2);
}

