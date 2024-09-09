#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

double naive(vector<int> nums){
  sort(nums.begin(), nums.end());
  int mid = nums.size() / 2;
  double ret = 0;
  if (nums.size() % 2 == 0){
    ret = (nums[mid] + nums[mid-1]) / 2.0;
  } else {
    ret = nums[mid];
  }
  //LOG(INFO) << "nums: " << nums << " median:" << ret;
  return ret;
}

vector<double> naive(vector<int>&nums, int k){
  vector<double> ret;
  for(int i=0, end=i+k; end<=nums.size(); i++, end++){
    vector<int> wnd{nums.begin() + i, nums.begin() + end};
    auto v = naive(wnd);
    ret.push_back(v);
  }
  return ret;
}

TEST(kk, t1) {
  Solution sol;
  int k = 3;
  vector<int> nums{1,3,-1,-3,5,3,6,7};
  vector<double> expect{1,-1,-1,3,5,6};
  vector<double> expect2 = naive(nums, k);

  EXPECT_EQ(sol.medianSlidingWindow(nums, k), expect);
  EXPECT_EQ(expect, expect2);

  k=4;
  auto expect4 = naive(nums, k);
  EXPECT_EQ(sol.medianSlidingWindow(nums, k), expect4);
}

TEST(kk, t1_1) {
  Solution sol;
  int k = 3;
  vector<int> nums{3, 6, 7, 5, 3, 5, 6};
  vector<double> expect{6,6,5,5,5};

  EXPECT_EQ(sol.medianSlidingWindow(nums, k), expect);
}

TEST(kk, t1_2) {
  Solution sol;
  int k = 2;
  vector<int> nums{2147483647,2147483647};
  vector<double> expect{2147483647};

  EXPECT_EQ(sol.medianSlidingWindow(nums, k), expect);
}




#if 1
TEST(kk, t2) {
  Solution sol;
  int k = 0;
  vector<int> nums;
  for(int i=0; i<20; i++){
    nums.push_back(rand() % 10);
  }
  LOG(INFO) << nums;

  for(int k=2;k<7;k++){
    auto expect = naive(nums, k);
    auto actual = sol.medianSlidingWindow(nums, k);
    LOG(INFO) << "k= " << k;
    EXPECT_EQ(expect, actual);
  }
}

#endif
