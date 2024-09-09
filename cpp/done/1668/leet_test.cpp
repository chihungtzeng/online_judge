#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maxRepeating("ababc", "ab"), 2);
  EXPECT_EQ(sol.maxRepeating("ababc", "ba"), 1);
  EXPECT_EQ(sol.maxRepeating("ababc", "ac"), 0);
  EXPECT_EQ(sol.maxRepeating("aaaaaa", "aa"), 3);
  EXPECT_EQ(sol.maxRepeating("aaaaaaa", "aa"), 3);
  EXPECT_EQ(sol.maxRepeating("aaaaaaaa", "aa"), 4);
}

