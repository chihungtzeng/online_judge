#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minNumberOfFrogs("croakcroak"), 1);
#if 1 
  EXPECT_EQ(sol.minNumberOfFrogs("crcoakroak"), 2);
  EXPECT_EQ(sol.minNumberOfFrogs("croakcrook"), -1);
  EXPECT_EQ(sol.minNumberOfFrogs("croakcroa"), -1);
  EXPECT_EQ(sol.minNumberOfFrogs("aoocrrackk"), -1);
#endif  
}

