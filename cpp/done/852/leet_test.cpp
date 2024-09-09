#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {0,1,0};
  EXPECT_EQ(sol.peakIndexInMountainArray(arr), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {0,2,1,0};
  EXPECT_EQ(sol.peakIndexInMountainArray(arr), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {0,10,5,2};
  EXPECT_EQ(sol.peakIndexInMountainArray(arr), 1);
}

TEST(kk, t4_0) {
  Solution sol;
  vector<int> arr = {0,1, 2, 3, 4, 5};
  EXPECT_EQ(sol.peakIndexInMountainArray(arr), 5);
}


TEST(kk, t4_1) {
  Solution sol;
  vector<int> arr = {5, 4, 3, 2, 1, 0};
  EXPECT_EQ(sol.peakIndexInMountainArray(arr), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr;
  int pos = 1773;
  int cur = 0;
  arr.push_back(0);
  srand(time(nullptr));
  for(int i=1; i<10000; i++){
    int val = 0;
    if (i <= pos) {
      val = arr[i-1] + rand() % 10 + 1;
    } else {
      val = arr[i-1] - rand() % 10 - 1;
    }
    arr.push_back(val);
  }
  EXPECT_EQ(sol.peakIndexInMountainArray(arr), 1773);
}

