#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int memory1 = 2, memory2 = 2;
  vector<int> expect{3,1,0};
  EXPECT_EQ(sol.memLeak(memory1, memory2), expect);
}

TEST(kk, t2) {
  Solution sol;
  int memory1 = 8, memory2 = 11;
  vector<int> expect{6,0,4};
  EXPECT_EQ(sol.memLeak(memory1, memory2), expect);
}

TEST(kk, t3) {
  Solution sol;
  int memory1 = 0, memory2 = 0;
  vector<int> expect{1,0,0};
  EXPECT_EQ(sol.memLeak(memory1, memory2), expect);
}

TEST(kk, t4) {
  Solution sol;
  int memory1 = 0, memory2 = 10;
  vector<int> expect{5,0,0};
  EXPECT_EQ(sol.memLeak(memory1, memory2), expect);
}

TEST(kk, t5) {
  Solution sol;
  int memory1 = 0, memory2 = 11;
  vector<int> expect{5,0,1};
  EXPECT_EQ(sol.memLeak(memory1, memory2), expect);
}

TEST(kk, t6) {
  Solution sol;
  int memory1 = 0x7fffffff, memory2 = 0x7fffffff;
  vector<int> expect{92681, 88047, 41707};
  EXPECT_EQ(sol.memLeak(memory1, memory2), expect);
}

