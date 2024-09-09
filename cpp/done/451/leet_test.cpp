#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.frequencySort("tree"), "eert");
  auto s = sol.frequencySort("cccaaa");
  EXPECT_TRUE(s == "cccaaa" || s == "aaaccc");
  s = sol.frequencySort("Aabb");
  EXPECT_TRUE(s == "bbaA" || s == "bbAa");
}

