#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{2,1,3,5,4,6,7};
  EXPECT_EQ(sol.getWinner(arr, 2), 5);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr{3, 2,1};
  EXPECT_EQ(sol.getWinner(arr, 10), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr{1,9,8,2,3,7,6,4,5};
  EXPECT_EQ(sol.getWinner(arr, 7), 9);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr{1,11,22,33,44,55,66,77,88,99};
  EXPECT_EQ(sol.getWinner(arr, 1000000000), 99);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr{1,25,35,42,68,70};
  EXPECT_EQ(sol.getWinner(arr, 1), 25);
}
