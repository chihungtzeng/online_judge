#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> queries{3,1,2,1};
  vector<int> expect{2,1,2,1};
  EXPECT_EQ(sol.processQueries(queries, 5), expect);
  vector<int> nums{3,1,4,1,5,9,2,6,2,7,1,8,2,8};
}

