#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  int n = 3, k = 7;
  vector<int> expect{ 181, 292, 707, 818, 929 };
  auto actual = sol.numsSameConsecDiff(n, k);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t2)
{
  Solution sol;
  int n = 2, k = 1;
  vector<int> expect{ 10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98 };
  auto actual = sol.numsSameConsecDiff(n, k);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t3)
{
  Solution sol;

  int n = 2, k = 0;
  vector<int> expect{ 11, 22, 33, 44, 55, 66, 77, 88, 99 };
  auto actual = sol.numsSameConsecDiff(n, k);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

