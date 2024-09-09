#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> data{197, 130, 1};

  EXPECT_TRUE(sol.validUtf8(data));
  data = {235, 140, 4};
  EXPECT_FALSE(sol.validUtf8(data));
}

