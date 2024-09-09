#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.splitString("1234"), false);
  EXPECT_EQ(sol.splitString("050043"), true);
  EXPECT_EQ(sol.splitString("9080701"), false);
  EXPECT_EQ(sol.splitString("10009998"), true);
  EXPECT_EQ(sol.splitString("3210"), true);
  EXPECT_EQ(sol.splitString("200100"), true);
  EXPECT_EQ(sol.splitString("3202872336"), false);
  EXPECT_EQ(sol.splitString("6442450944214748364"), false);
  EXPECT_EQ(sol.splitString("98765432119876543210"), true);

}

