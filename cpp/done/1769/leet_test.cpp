#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> expect{1,1,3};
  EXPECT_EQ(sol.minOperations("110"), expect);
}

TEST(kk, t2) {
  Solution sol;

  vector<int> expect{11,8,5,4,3,4};
  EXPECT_EQ(sol.minOperations("001011"), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> expect{0,0,0,0};
  EXPECT_EQ(sol.minOperations("0000"), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> expect{0};
  EXPECT_EQ(sol.minOperations("1"), expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> expect{0};
  EXPECT_EQ(sol.minOperations("0"), expect);
}

