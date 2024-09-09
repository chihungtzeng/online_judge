#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.checkIfCanBreak("abc","xya"), true);
  EXPECT_EQ(sol.checkIfCanBreak("abe","acd"), false);
  EXPECT_EQ(sol.checkIfCanBreak("leetcodee","interview"), true);
}

