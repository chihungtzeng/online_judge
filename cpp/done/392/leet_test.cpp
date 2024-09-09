#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_TRUE(sol.isSubsequence("abc", "ahbgdc"));
  EXPECT_FALSE(sol.isSubsequence("axc", "ahbgdc"));
}

