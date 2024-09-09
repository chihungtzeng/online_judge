#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_FALSE(sol.isValidSerialization("1,#"));
  EXPECT_FALSE(sol.isValidSerialization("9,#,#,1"));
}

TEST(kk, t2) {
  Solution sol;

  LOG(INFO) << "t2";
  EXPECT_TRUE(sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
}

