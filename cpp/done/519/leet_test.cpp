#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution* obj = new Solution(1, 2);
  LOG(INFO) << "segs_: " << obj->segs_;
  LOG(INFO) << obj->flip();
  LOG(INFO) << "segs_: " << obj->segs_;
  LOG(INFO) << obj->flip();
  EXPECT_EQ(obj->segs_.size(), 0);
  delete obj;
}

TEST(kk, t2) {
  Solution* obj = new Solution(10000, 10000);
  for(int i = 0; i< 1000; i++){
    LOG(INFO) << obj->flip();
  }
  LOG(INFO) << "# segs: " << obj->segs_.size();
  delete obj;
}

