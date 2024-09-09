#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.kthGrammar(1, 1), 0);
  EXPECT_EQ(sol.kthGrammar(2, 1), 0);
  EXPECT_EQ(sol.kthGrammar(2, 2), 1);
  EXPECT_EQ(sol.kthGrammar(4, 5), 1);
}

