#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.palindromePartition("abc", 2), 1);
  EXPECT_EQ(sol.palindromePartition("aabbc", 3), 0);
  EXPECT_EQ(sol.palindromePartition("leetcode", 8), 0);
  EXPECT_EQ(sol.palindromePartition("returntheminimalnumberofcharactersthatyouneedtochangetodividethestring", 5), 23);
  EXPECT_EQ(sol.palindromePartition("returntheminimalnumberofcharactersthatyouneedtochangetodividethestring", 8), 21);
  EXPECT_EQ(sol.palindromePartition("returntheminimalnumberofcharactersthatyouneedtochangetodividethestring", 9), 20);
  EXPECT_EQ(sol.palindromePartition("returntheminimalnumberofcharactersthatyouneedtochangetodividethestring", 10), 19);
}

