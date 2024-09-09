#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  
  EXPECT_EQ(sol.countVowelPermutation(1), 5);
}

TEST(kk, t2) {
  Solution sol;

  EXPECT_EQ(sol.countVowelPermutation(2), 10);
}

TEST(kk, t3) {
  Solution sol;

  EXPECT_EQ(sol.countVowelPermutation(5), 68);
}

TEST(kk, t4) {
  Solution sol;

  EXPECT_EQ(sol.countVowelPermutation(20000), 759959057);
}

