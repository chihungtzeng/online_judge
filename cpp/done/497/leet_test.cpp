#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  vector<vector<int>> rects{{1,1,5,5}};

 Solution* obj = new Solution(rects);
 LOG(INFO) << obj->pick();
 delete obj;
}

TEST(kk, t2) {
  vector<vector<int>> rects{{-2,-2,-1,-1}, {1,0,3,0}, {2,2,5,5}};

 Solution* obj = new Solution(rects);
 bool cover1 = false;
 for(int i=0; i<1000; i++){
  auto pick = obj->pick();
  bool match = false;
  for(int j=0; j<rects.size(); j++){
    if (pick[0] >= rects[j][0] && pick[0] <= rects[j][2] && pick[1] >= rects[j][1] && pick[1] <= rects[j][3]){
      match = true;
    }
    if (j==1) {
      cover1 = true;
    }
  }
  EXPECT_TRUE(match);
 }
 EXPECT_TRUE(cover1);
 delete obj;
}

