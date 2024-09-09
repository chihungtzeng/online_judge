#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> mat = {{1,3,11},{2,4,6}};
  int k = 5;
  EXPECT_EQ(sol.kthSmallest(mat, k), 7);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> mat = {{1,3,11},{2,4,6}};
  EXPECT_EQ(sol.kthSmallest(mat, 9), 17);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> mat = {{1,10,10},{1,4,5},{2,3,6}};
  EXPECT_EQ(sol.kthSmallest(mat, 7), 9);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> mat = {{1,1,10},{2,2,9}};
  EXPECT_EQ(sol.kthSmallest(mat, 7), 12);
}

