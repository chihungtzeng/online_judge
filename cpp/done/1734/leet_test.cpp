#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> encoded = {3, 1};
  vector<int> expect{1, 2, 3};
  EXPECT_EQ(sol.decode(encoded), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> encoded = {6, 5, 4, 6};
  vector<int> expect{2, 4, 1, 5, 3};
  EXPECT_EQ(sol.decode(encoded), expect);
}

