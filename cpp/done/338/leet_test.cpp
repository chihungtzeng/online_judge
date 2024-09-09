#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_FALSE(sol.canConstruct("a", "b"));
  EXPECT_FALSE(sol.canConstruct("aa", "ab"));
  EXPECT_TRUE(sol.canConstruct("aa", "aab"));
}

