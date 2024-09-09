#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> slices = {1, 2, 3, 4, 5, 6};

  EXPECT_EQ(sol.maxSizeSlices(slices), 10);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> slices = {8, 9, 8, 6, 1, 1};
  EXPECT_EQ(sol.maxSizeSlices(slices), 16);
}
TEST(kk, t3) {
  Solution sol;
  vector<int> slices = {4, 1, 2, 5, 8, 3, 1, 9, 7};
  EXPECT_EQ(sol.maxSizeSlices(slices), 21);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> slices = {3, 1, 2};
  EXPECT_EQ(sol.maxSizeSlices(slices), 3);
}

#if 0
TEST(kk, t5) {
  Solution sol;
  vector<int> slices = {6, 3, 1, 2, 6, 2, 4, 3, 10, 4, 1, 4, 6, 5, 5,
                        3, 4, 7, 6, 5, 8, 7, 3, 8,  8, 1, 7, 1, 7, 8};
  EXPECT_EQ(sol.maxSizeSlices(slices), 70);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> slices;
  for(int i=0; i<498; i++){
    slices.push_back(rand() % 1000 + 1);
  }
  sol.maxSizeSlices(slices);
}
#endif
