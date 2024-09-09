#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maxDiff(555), 888 );
  EXPECT_EQ(sol.maxDiff(123456), 820000 );
  EXPECT_EQ(sol.maxDiff(10000), 80000 );
  EXPECT_EQ(sol.maxDiff(9288), 8700 );
  EXPECT_EQ(sol.maxDiff(19), 89 );
  EXPECT_EQ(sol.maxDiff(111), 888);
  EXPECT_EQ(sol.maxDiff(10), 80 );
  for(int i=1; i<= 9 ; i++){
    EXPECT_EQ(sol.maxDiff(i), 8);
  }
}

