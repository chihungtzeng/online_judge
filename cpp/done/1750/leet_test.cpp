#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minimumLength("ca"), 2);
  EXPECT_EQ(sol.minimumLength("cabaabac"), 0);
  EXPECT_EQ(sol.minimumLength("a"), 1);
  EXPECT_EQ(sol.minimumLength("aabccabba"), 3);
  EXPECT_EQ(sol.minimumLength("bbbbbbbbbbbbbbbbbbb"), 0);
}

