#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string word = "CAKE";
  EXPECT_EQ(sol.minimumDistance(word), 3);
}

TEST(kk, t2) {
  Solution sol;
  string word = "HAPPY";
  EXPECT_EQ(sol.minimumDistance(word), 6);
}

TEST(kk, t3) {
  Solution sol;
  string word = "NEW";
  EXPECT_EQ(sol.minimumDistance(word), 3);
}

TEST(kk, t4) {
  Solution sol;
  string word = "YEAR";
  EXPECT_EQ(sol.minimumDistance(word), 7);
}

