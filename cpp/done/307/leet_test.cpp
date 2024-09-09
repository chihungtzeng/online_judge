#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

int sum_range(int i, int j, vector<int>& nums){
  int ret = 0;
  for(auto k=i; k<=j; k++){
    ret += nums[k];
  }
  return ret;
}


TEST(kk, t1) {
  std::vector<int> nums{1, 3, 5};
  NumArray* obj = new NumArray(nums);

  EXPECT_EQ(obj->sumRange(0,2), 9);
  obj->update(1,2);
  EXPECT_EQ(obj->sumRange(0,2), 8);
  delete obj;
}

#if 0
TEST(kk, t2) {
  std::vector<int> nums{3,1,4,1,5,9,2,6,2,7,1,8,2,8}; // 14
  NumArray* obj = new NumArray(nums);

  int i=0, j=0;
  i=3; j=3;
  EXPECT_EQ(obj->sumRange(i, j), sum_range(i, j, obj->nums_));

  i=0; j=13;
  EXPECT_EQ(obj->sumRange(i, j), sum_range(i, j, obj->nums_));
  obj->update(1,2);
  EXPECT_EQ(obj->sumRange(i, j), sum_range(i, j, obj->nums_));
  obj->update(7, 98);
  i=3;
  j = 11;
  EXPECT_EQ(obj->sumRange(i, j), sum_range(i, j, obj->nums_));
  obj->update(1, 98);
  EXPECT_EQ(obj->sumRange(i, j), sum_range(i, j, obj->nums_));
  obj->update(10, 980);
  obj->update(11, 981);
  obj->update(12, 1981);
  obj->update(13, 19810);
  EXPECT_EQ(obj->sumRange(i, j), sum_range(i, j, obj->nums_));
  delete obj;
}

TEST(kk, t3) {
  std::vector<int> nums;
  NumArray* obj = new NumArray(nums);
  delete obj;
}
#endif


