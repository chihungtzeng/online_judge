#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{1,3,5};
  EXPECT_EQ(sol.numOfSubarrays(arr), 4);
}
TEST(kk, t2) {
  Solution sol;
  vector<int> arr{2,4,6};
  EXPECT_EQ(sol.numOfSubarrays(arr), 0);
}
TEST(kk, t3) {
  Solution sol;
  vector<int> arr{1,2,3,4,5,6,7};
  EXPECT_EQ(sol.numOfSubarrays(arr), 16);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr{100,100,99,99};
  EXPECT_EQ(sol.numOfSubarrays(arr), 4);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr{7};
  EXPECT_EQ(sol.numOfSubarrays(arr), 1);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> arr{1,2,3,4,5,6,7,3,1,4,1,5,9,2,6,2,7,1,8,2,8,3,1,4,7,7,1};
  EXPECT_EQ(sol.numOfSubarrays(arr), 187);
}


