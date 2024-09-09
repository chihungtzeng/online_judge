#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  string s = "leetcode";
  int power = 7, modulo = 20, k = 2, hashValue = 0;
  EXPECT_EQ(sol.subStrHash(s, power, modulo, k, hashValue), "ee");
}

TEST(kk, t2)
{
  Solution sol;
  string s = "fbxzaad";
  int power = 31, modulo = 100, k = 3, hashValue = 32;
  EXPECT_EQ(sol.subStrHash(s, power, modulo, k, hashValue), "fbx");
}

