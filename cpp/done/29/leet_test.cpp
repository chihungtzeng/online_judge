#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  int dividend = 10, divisor = 3;
  EXPECT_EQ(sol.divide(dividend, divisor), 3);
  EXPECT_EQ(sol.divide(-7, 3), -2);
  EXPECT_EQ(sol.divide(-7, -3), 2);
  EXPECT_EQ(sol.divide(1, 1), 1);
  EXPECT_EQ(sol.divide(INT_MIN, 3), -715827882 );

}

TEST(kk, t2)
{
  Solution sol;
  EXPECT_EQ(sol.divide(INT_MAX, INT_MIN), 0);
  EXPECT_EQ(sol.divide(INT_MAX, 2), 1073741823);
  EXPECT_EQ(sol.divide( 2147483647, 2) , 1073741823);


}

TEST(kk, t3)
{
  Solution sol;
  EXPECT_EQ(sol.divide(INT_MIN + 1, INT_MIN), 0);
  EXPECT_EQ(sol.divide(INT_MIN, INT_MIN), 1);
  EXPECT_EQ(sol.divide(INT_MAX, -1), INT_MIN + 1);
  EXPECT_EQ(sol.divide(INT_MAX, 1), INT_MAX);
  EXPECT_EQ(sol.divide(INT_MIN, -1), INT_MAX);
  EXPECT_EQ(sol.divide(INT_MIN, 1), INT_MIN);
}

