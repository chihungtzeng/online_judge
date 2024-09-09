#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countLargestGroup(24), 5);
  EXPECT_EQ(sol.countLargestGroup(10000), 1);
  for(int i=1; i<10000; i++){
    sol.countLargestGroup(i);
  }
}

