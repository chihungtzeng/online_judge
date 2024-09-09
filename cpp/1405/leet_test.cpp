#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.longestDiverseString(7,1,0), "aabaa");
  EXPECT_EQ(sol.longestDiverseString(1,1,7).size(), string("ccaccbcc").size());
  EXPECT_EQ(sol.longestDiverseString(2,2,1).size(), string("aabbc").size());
  EXPECT_EQ(sol.longestDiverseString(1,4,5).size(), string("ccbbccbbac").size());
}

TEST(kk, t2) {
  Solution sol;
  EXPECT_EQ(sol.longestDiverseString(3,0,4).size(), string("ccaacca").size());
  EXPECT_EQ(sol.longestDiverseString(0,8,11).size(), string("ccbccbbccbbccbbccbc").size());
}
