#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "leet.cpp"
#include <ctime>
#include <gtest/gtest.h>

void put_random_ints(std::vector<int> &nums) {
  srand(time(nullptr));
  constexpr int amount = 1000000;
  constexpr int mod = 10000000;
  nums.clear();
  nums.reserve(amount);
  for (int i = 0; i < amount; i++) {
    nums.push_back(rand() % mod);
  }
}

TEST(kk, t1) {
  std::vector<int> nums;
  put_random_ints(nums);

  radix_sort(nums);
  EXPECT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(kk, t2) {
  std::vector<int> nums;
  put_random_ints(nums);

  std::sort(nums.begin(), nums.end());
  EXPECT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(kk, t3) {
  std::vector<int> nums{10, 1};
  radix_sort(nums);
  EXPECT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

