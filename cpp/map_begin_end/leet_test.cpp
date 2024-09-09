#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

constexpr int ub = 5000;

TEST(kk, t1) {
  vector<int> nums;
  map<int, int> maps;

  nums.push_back(-1);
  maps[-1] = 1;

  for(int i=0; i<10000; i++){
    int r = rand() % ub;
    nums.push_back(r);
    maps[r] = 1;
//    LOG(INFO) << nums;
    int m = *min_element(nums.begin(), nums.end());
    int M = *max_element(nums.begin(), nums.end());
    EXPECT_EQ(maps.begin()->first, m);
    EXPECT_EQ(maps.rbegin()->first, M);

  }

}

