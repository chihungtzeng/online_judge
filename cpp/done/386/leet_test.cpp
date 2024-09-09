#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> expect{1,10,11,12,13,2,3,4,5,6,7,8,9};

  EXPECT_EQ(sol.lexicalOrder(13), expect);
  
//  LOG(INFO) << sol.lexicalOrder(37);
  sol.lexicalOrder(5000000);
}

