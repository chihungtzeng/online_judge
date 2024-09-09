#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  std::vector<int> nums{1,2,3,3,3};
  Solution sol(nums);
  // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
  for(int i=0; i<10; i++)
  {
    auto idx = sol.pick(3);
    LOG(INFO) << idx;
    EXPECT_TRUE(idx >= 2 && idx <= 4);
  }

  // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
  EXPECT_EQ(sol.pick(1), 0);
}

