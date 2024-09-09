#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> code = {5, 7, 1, 4};
  int k = 3;
  vector<int> expect{12, 10, 16, 13};
  EXPECT_EQ(sol.decrypt(code, k), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> code = {1, 2, 3, 4};
  int k = 0;
  vector<int> expect{0, 0, 0, 0};
  EXPECT_EQ(sol.decrypt(code, k), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> code = {2, 4, 9, 3};
  int k = -2;
  vector<int> expect{12, 5, 6, 13};
  EXPECT_EQ(sol.decrypt(code, k), expect);
}

