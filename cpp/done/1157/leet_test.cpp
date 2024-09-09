#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  vector<int> arr{1, 1, 2, 2, 1, 1};
  MajorityChecker* obj = new MajorityChecker(arr);
  EXPECT_EQ(obj->query(0, 5, 4), 1);
  EXPECT_EQ(obj->query(0, 3, 3), -1);
  EXPECT_EQ(obj->query(2, 3, 2), 2);
  EXPECT_EQ(obj->query(2, 2, 1), 2);
  delete obj;
}

TEST(kk, t2) {
  vector<int> arr;
  srand(time(NULL));
  for (int i = 0; i < 20000; i++) {
    arr.push_back(1 + rand() % 20000);
  }

  MajorityChecker* obj = new MajorityChecker(arr);
  const int n = 20000;
  for (int i = 0; i < 1000; i++) {
    int left = rand() % n;
    int right = rand() % n;
    if (left > right) {
      swap(left, right);
    }
    int threhold = 1 + (right - left + 1) / 2 + rand() % 10;
    obj->query(left, right, threhold);
  }
  delete obj;
}
