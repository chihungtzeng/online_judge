#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

int naive(vector<int> numsi){
  int ret = 0;
  vector<int64_t> nums;
  for(auto x: numsi){
    nums.push_back(x);
  }
  for(int i=0; i<nums.size(); i++){
    for(int j=i+1; j<nums.size(); j++){
      if (nums[i] -nums[j] > nums[j]) ret++;
    }
  }
  return ret;
}

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,3,2,3,1};
  EXPECT_EQ(sol.reversePairs(nums), 2);
}
TEST(kk, t2) {
  Solution sol;
  vector<int> nums{2,4,3,5,1};
  EXPECT_EQ(sol.reversePairs(nums), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{3,1,4,1,5,9,2,6};
  auto expect = naive(nums);
  EXPECT_EQ(sol.reversePairs(nums), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};

  auto expect = naive(nums);
  EXPECT_EQ(sol.reversePairs(nums), expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums{2147483647,2147483647,-2147483647,-2147483647,-2147483647,2147483647};

  auto expect = naive(nums);
  EXPECT_EQ(sol.reversePairs(nums), expect);
}

