#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  vector<int> nums{1,2,3};
  Solution* obj = new Solution(nums);

  LOG(INFO) << obj->shuffle();
  LOG(INFO) << obj->reset();
  LOG(INFO) << obj->shuffle();
  EXPECT_EQ(obj->reset(), nums);
  delete obj;
}

TEST(kk, t2) {
  vector<int> nums{3,1,4,1,5,9,2,6};
  Solution* obj = new Solution(nums);

  LOG(INFO) << obj->shuffle();
  LOG(INFO) << obj->reset();
  LOG(INFO) << obj->shuffle();
  EXPECT_EQ(obj->reset(), nums);
  delete obj;
}

