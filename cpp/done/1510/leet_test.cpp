#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.winnerSquareGame(1), true);
  EXPECT_EQ(sol.winnerSquareGame(2), false);
  EXPECT_EQ(sol.winnerSquareGame(4), true);
  EXPECT_EQ(sol.winnerSquareGame(7), false);
  EXPECT_EQ(sol.winnerSquareGame(17), false);
  EXPECT_EQ(sol.winnerSquareGame(10000), true);
  EXPECT_EQ(sol.winnerSquareGame(100000), true);
}

