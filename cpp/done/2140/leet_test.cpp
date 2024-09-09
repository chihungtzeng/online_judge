#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> questions = { { 3, 2 }, { 4, 3 }, { 4, 4 }, { 2, 5 } };
  EXPECT_EQ(sol.mostPoints(questions), 5);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> questions = { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 5 } };
  EXPECT_EQ(sol.mostPoints(questions), 7);
}

TEST(kk, t3)
{
  Solution sol;

  vector<vector<int>> questions = { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 5 },
                                    { 6, 6 }, { 7, 7 }, { 8, 8 }, { 9, 9 }, { 10, 10 } };
  EXPECT_EQ(sol.mostPoints(questions), 15);
}

