#include <gtest/gtest.h>
#include "leet.cpp"

TEST(haha, t1)
{
  Solution sol;
  vector<int> expect{1,2,1};
  EXPECT_EQ(expect, sol.getRow(2));
  vector<int> expect3{1,3,3,1};
  EXPECT_EQ(expect3, sol.getRow(3));
}
