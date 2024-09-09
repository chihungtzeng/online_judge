#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

int _range_sum(std::vector<int>& nums, int lower, int upper){
  std::vector<int64_t> psum(nums.size() + 1);
  for(size_t i=1; i<=nums.size(); i++){
    psum[i] = psum[i-1] + nums[i-1];
  }
  int cnt = 0;
  for(int i=0; i<nums.size(); i++){
    for(int j=i; j<nums.size(); j++){
      auto rsum = psum[j+1] - psum[i];
      if (rsum >= lower && rsum <= upper){
        cnt++;
      }
    }
  }
  return cnt;
}

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{-2,5,-1};
  int lower = -2, upper = 2;
  EXPECT_EQ(sol.countRangeSum(nums, lower, upper), _range_sum(nums, lower, upper));
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums;
  srand(time(NULL));
  for(int i=0; i<1000; i++){
    int j = rand() % 100;
    if (rand() % 2 > 0) {
      j = -j;
    }
    nums.push_back(j);
  }
  int lower = -50, upper = 50;
  int cnt = _range_sum(nums, lower, upper);
  LOG(INFO) << "cnt: " << cnt;
  EXPECT_EQ(sol.countRangeSum(nums, lower, upper), cnt);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{-2147483647,0,-2147483647,2147483647};
  int lower = -564;
  int upper = 3864;
  int cnt = _range_sum(nums, lower, upper);
  LOG(INFO) << "cnt: " << cnt;
  EXPECT_EQ(sol.countRangeSum(nums, lower, upper), cnt);
}



