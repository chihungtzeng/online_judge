#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_TRUE(sol.isPowerOfFour(1));
  EXPECT_TRUE(sol.isPowerOfFour(4));
  EXPECT_TRUE(sol.isPowerOfFour(16));
  EXPECT_TRUE(sol.isPowerOfFour(64));
  EXPECT_TRUE(sol.isPowerOfFour(256));
  EXPECT_TRUE(sol.isPowerOfFour(1024));
  for(int i=17; i<64; i++){
    if (sol.isPowerOfFour(i)) {
      LOG(INFO) << i;
      EXPECT_FALSE(true);
    }
  }
  for(int i=65; i<256; i++){
    if (sol.isPowerOfFour(i)) {
      LOG(INFO) << i;
      EXPECT_FALSE(true);
    }
  }
  for(int i=257; i<1024; i++){
    if (sol.isPowerOfFour(i)) {
      LOG(INFO) << i;
      EXPECT_FALSE(true);
    }
  }


}

