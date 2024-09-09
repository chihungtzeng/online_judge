#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minDistance("sea", "eat"), 2);
  EXPECT_EQ(sol.minDistance("ABCD", "ACBAD"), 3);
  EXPECT_EQ(sol.minDistance("", ""), 0);
  EXPECT_EQ(sol.minDistance("", "abc"), 3);
  EXPECT_EQ(sol.minDistance("park", "spake"), 3);
}

TEST(kk, t2) {
  Solution sol;
  EXPECT_EQ(sol.minDistance("a", "ab"), 1);
}
