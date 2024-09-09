#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minInsertions("zzazz"), 0);
  EXPECT_EQ(sol.minInsertions("mbadm"), 2);
  EXPECT_EQ(sol.minInsertions("leetcode"), 5);
  EXPECT_EQ(sol.minInsertions("g"), 0);
  EXPECT_EQ(sol.minInsertions("no"), 1);
  EXPECT_EQ(sol.minInsertions("fjbixpdtkbcevrjrvecbktdpxibjf"), 0);
}

TEST(kk, t2) {
  Solution sol;
  string input;
  for(int i=0;i<500; i++){
    input.push_back('a' + i % 26);
  }
  EXPECT_EQ(sol.minInsertions(input), 461);
}
