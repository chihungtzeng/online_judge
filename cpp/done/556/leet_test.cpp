#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.nextGreaterElement(12), 21);
  EXPECT_EQ(sol.nextGreaterElement(21), -1);
  EXPECT_EQ(sol.nextGreaterElement(4321), -1);
  EXPECT_EQ(sol.nextGreaterElement(1234), 1243);
  EXPECT_EQ(sol.nextGreaterElement(230241), 230412);
  EXPECT_EQ(sol.nextGreaterElement(12222333), 12223233);
  EXPECT_EQ(sol.nextGreaterElement(1999999999), -1);

  for(int i=0; i<10; i++){
    EXPECT_EQ(sol.nextGreaterElement(i), -1);
  }

}

