#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"
#include <ctime>
#include <cstdlib>


constexpr int niters = 50000;
constexpr int nelems = 1000;
std::vector<int> g_nums[niters];
std::vector<int> g_mins;


int gen_rand_nums(std::vector<int>& nums){
  srand(time(nullptr));
  nums.clear();
  int least = 0;
  for(int i=0; i<nelems; i++)
  {
    nums.push_back(rand() % 100);
  }
  sort(nums.begin(), nums.end());
  least = nums[0];

  std::vector<int> left, right;
  left.reserve(nelems);
  right.reserve(nelems);
  int pivot = rand() % nelems;
  for(int i=0; i<pivot; i++)
  {
    left.push_back(nums[i]);
  }
  for(int i=pivot; i<nelems; i++)
  {
    right.push_back(nums[i]);
  }
  for(int i=0; i<right.size(); i++)
  {
    nums[i] = right[i];
  }
  for(int i=right.size(); i<nelems; i++)
  {
    nums[i] = left[i-right.size()];
  }
  return least;
}

TEST(kk, t0) {
  for(int i = 0; i<niters; i++)
  {
    auto least = gen_rand_nums(g_nums[i]);
    g_mins.push_back(least);
  }
}

TEST(kk, t1) {
  Solution sol;
  std::vector<int> nums{1,3,5};
  EXPECT_EQ(sol.findMin(nums), 1);
}

TEST(kk, t2) {
  Solution sol;
  std::vector<int> nums{2,2,2,0,1};
  EXPECT_EQ(sol.findMin(nums), 0);
}

TEST(kk, t3) {
  Solution sol;
  std::vector<int> nums{4,5,6,7,0,1,2};
  EXPECT_EQ(sol.findMin(nums), 0);
}

TEST(kk, t4) {
  Solution sol;
  std::vector<int> nums{4,5,6,6,6,7,0,1,2};
  EXPECT_EQ(sol.findMin(nums), 0);
}

TEST(kk, t5) {
  Solution sol;
  std::vector<int> nums;
  for(int i = 0; i<niters; i++)
  {
    LOG(INFO) << i;
    EXPECT_EQ(sol.findMin(g_nums[i]), g_mins[i]);
  }
}
