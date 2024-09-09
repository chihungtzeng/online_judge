#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  //vector<int> sweetness = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  //vector<int> sweetness = {10, 9,8,7,6,5,4,3,2,1};  // 7
  vector<int> sweetness = {9,8,7,6,5,4,3,2,1};  // 7
  int K = 5;
  EXPECT_EQ(sol.maximizeSweetness(sweetness, K), 6);
}

/*
TEST(kk, t2) {
  Solution sol;
  vector<int> sweetness = {5, 6, 7, 8, 9, 1, 2, 3, 4};
  int K = 8;
  EXPECT_EQ(sol.maximizeSweetness(sweetness, K), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> sweetness = {1, 2, 2, 1, 2, 2, 1, 2, 2};
  int K = 2;
  EXPECT_EQ(sol.maximizeSweetness(sweetness, K), 5);
}
*/
