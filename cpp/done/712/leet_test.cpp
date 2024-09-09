#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minimumDeleteSum("sea", "tea"), 231);
  EXPECT_EQ(sol.minimumDeleteSum("delete", "leet"), 403);
}

