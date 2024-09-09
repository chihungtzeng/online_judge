#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{4,3,2,1,0};
  vector<int> arr2{1,0,2,3,4};

  EXPECT_EQ(sol.maxChunksToSorted(arr), 1);
  EXPECT_EQ(sol.maxChunksToSorted(arr2), 4);
}

