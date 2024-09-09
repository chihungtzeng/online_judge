#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> cards = { 4, 1, 8, 7 };
  EXPECT_EQ(sol.judgePoint24(cards), true);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> cards = { 1, 2, 1, 2 };
  EXPECT_EQ(sol.judgePoint24(cards), false);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> cards = { 1, 9, 1, 2 };
  EXPECT_EQ(sol.judgePoint24(cards), true);
}

TEST(kk, t4)
{
  Solution sol;
  vector<int> cards = { 4, 7, 9, 9 };
  EXPECT_EQ(sol.judgePoint24(cards), true);
}

TEST(kk, t5)
{
  Solution sol;
  vector<int> cards = { 1, 1, 7, 7 };
  EXPECT_EQ(sol.judgePoint24(cards), false);
}

TEST(kk, t6)
{
  Solution sol;
  vector<int> cards = { 3, 4, 6, 7 };
  EXPECT_EQ(sol.judgePoint24(cards), false);
}




