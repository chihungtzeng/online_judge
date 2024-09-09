#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minInteger("4321", 4), "1342");
  EXPECT_EQ(sol.minInteger("100", 1), "010");
  EXPECT_EQ(sol.minInteger("36789", 1000), "36789");
  EXPECT_EQ(sol.minInteger("22", 22), "22");
  EXPECT_EQ(sol.minInteger("9438957234785635408", 23), "0345989723478563548");
}

