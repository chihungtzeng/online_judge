#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "aababbab";
  EXPECT_EQ(sol.minimumDeletions(s), 2);
}

TEST(kk, t2) {
  Solution sol;
  string s = "bbaaaaabb";
  EXPECT_EQ(sol.minimumDeletions(s), 2);
}

TEST(kk, t3) {
  Solution sol;

  string s = "aabbbbbbabbb";
  EXPECT_EQ(sol.minimumDeletions(s), 1);
}

