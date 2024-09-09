#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  std::vector<int> nums{1, 5, 1, 1, 6, 4};
  sol.wiggleSort(nums);
  LOG(INFO) << nums;
  for(int i=1; i<nums.size(); i+=2){
    EXPECT_TRUE(nums[i] > nums[i-1]);
    if (i != nums.size() - 1) {
      EXPECT_TRUE(nums[i] > nums[i+1]);
    }
  }
}

TEST(kk, t2) {
  Solution sol;

  std::vector<int> nums{1, 3, 2, 2, 3, 1};
  sol.wiggleSort(nums);
  LOG(INFO) << nums;
  for(int i=1; i<nums.size(); i+=2){
    EXPECT_TRUE(nums[i] > nums[i-1]);
    if (i != nums.size() - 1) {
      EXPECT_TRUE(nums[i] > nums[i+1]);
    }
  }
}

TEST(kk, t3) {
  Solution sol;

  std::vector<int> nums{5,4,3,2,1};
  sol.wiggleSort(nums);
  LOG(INFO) << nums;
  for(int i=1; i<nums.size(); i+=2){
    EXPECT_TRUE(nums[i] > nums[i-1]);
    if (i != nums.size() - 1) {
      EXPECT_TRUE(nums[i] > nums[i+1]);
    }
  }
}

TEST(kk, t4) {
  Solution sol;

  std::vector<int> nums{3,2,1};
  sol.wiggleSort(nums);
  LOG(INFO) << nums;
  for(int i=1; i<nums.size(); i+=2){
    EXPECT_TRUE(nums[i] > nums[i-1]);
    if (i != nums.size() - 1) {
      EXPECT_TRUE(nums[i] > nums[i+1]);
    }
  }
}

TEST(kk, t5) {
  Solution sol;

  std::vector<int> nums{3,2};
  sol.wiggleSort(nums);
  LOG(INFO) << nums;
  for(int i=1; i<nums.size(); i+=2){
    EXPECT_TRUE(nums[i] > nums[i-1]);
    if (i != nums.size() - 1) {
      EXPECT_TRUE(nums[i] > nums[i+1]);
    }
  }
}

TEST(kk, t6) {
  Solution sol;

  std::vector<int> nums{3};
  sol.wiggleSort(nums);
  LOG(INFO) << nums;
  for(int i=1; i<nums.size(); i+=2){
    EXPECT_TRUE(nums[i] > nums[i-1]);
    if (i != nums.size() - 1) {
      EXPECT_TRUE(nums[i] > nums[i+1]);
    }
  }
}

TEST(kk, t7) {
  Solution sol;

  std::vector<int> nums{};
  sol.wiggleSort(nums);
  EXPECT_EQ(nums.size(), 0);
}

TEST(kk, t8) {
  Solution sol;

  std::vector<int> nums{1,1,2,1,2,2,1  };
  sol.wiggleSort(nums);
  LOG(INFO) << nums;
  for(int i=1; i<nums.size(); i+=2){
    EXPECT_TRUE(nums[i] > nums[i-1]);
    if (i != nums.size() - 1) {
      EXPECT_TRUE(nums[i] > nums[i+1]);
    }
  }
}
TEST(kk, t9) {
  Solution sol;

  std::vector<int> nums{4,5,5,6};
  sol.wiggleSort(nums);
  LOG(INFO) << nums;
  for(int i=1; i<nums.size(); i+=2){
    EXPECT_TRUE(nums[i] > nums[i-1]);
    if (i != nums.size() - 1) {
      EXPECT_TRUE(nums[i] > nums[i+1]);
    }
  }
}



