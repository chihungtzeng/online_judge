#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 1, 2 };
  EXPECT_EQ(sol.maxScore(nums), 1);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 3, 4, 6, 8 };
  EXPECT_EQ(sol.maxScore(nums), 11);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 1, 2, 3, 4, 5, 6 };
  EXPECT_EQ(sol.maxScore(nums), 14);
}

TEST(kk, t4)
{
  Solution sol;
  vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
  EXPECT_EQ(sol.maxScore(nums), 138);
}

TEST(kk, t5)
{
  Solution sol;
  vector<int> nums = { 1373, 1811, 509, 2503, 113, 421, 79, 1373, 1811, 509, 2503, 113, 421, 79 };

  EXPECT_EQ(sol.maxScore(nums), 38856);
}

TEST(kk, t6)
{
  Solution sol;
  vector<int> nums = { 1231, 521, 2539, 1213, 2699, 1667, 1361, 1231, 521, 2539, 1213, 2699, 1667, 1361 };

  EXPECT_EQ(sol.maxScore(nums), 54546);
}

TEST(kk, t7)
{
  Solution sol;
  vector<int> nums = { 109497, 983516, 698308, 409009, 310455, 528595, 524079,
                       18036,  341150, 641864, 913962, 421869, 943382, 295019 };

  EXPECT_EQ(sol.maxScore(nums), 527);
}

TEST(kk, t8)
{
  Solution sol;
  vector<int> nums = { 9, 17, 16, 15, 18, 13, 18, 20 };

  EXPECT_EQ(sol.maxScore(nums), 91);
}

TEST(kk, t9)
{
  Solution sol;
  vector<int> nums = { 422, 975, 518, 579, 672, 121, 27, 624, 647, 733 };

  EXPECT_EQ(sol.maxScore(nums), 263);
}

