#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<char> chars{'a','a','b','b','c','c','c'};
  vector<char> expect{'a','2','b','2','c','3'};

  EXPECT_EQ(sol.compress(chars), 6);
  EXPECT_EQ(chars, expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<char> chars{'a','b','c'};
  vector<char> expect{'a','b','c'};

  EXPECT_EQ(sol.compress(chars), 3);
  EXPECT_EQ(chars, expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<char> chars{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
  vector<char> expect{'a','b','1','2'};


  EXPECT_EQ(sol.compress(chars), 4);
  EXPECT_EQ(chars, expect);
}

