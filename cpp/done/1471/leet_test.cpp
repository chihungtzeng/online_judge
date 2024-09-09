#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr{1,2,3,4,5};
  vector<int> expect{1,5};
  EXPECT_EQ(sol.median_of(arr), 3);
  auto actual = sol.getStrongest(arr, 2);
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr {1,1,3,5,5};
  vector<int> expect{5,5};
  EXPECT_EQ(sol.median_of(arr), 3);
  auto actual = sol.getStrongest(arr, 2);
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr{6,7,11,7,6,8};
  EXPECT_EQ(sol.median_of(arr), 7);
  vector<int> expect{11,8,6,6,7};
  auto actual = sol.getStrongest(arr, 5);
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr{6,-3,7,2,11};
  vector<int> expect{-3,11,2};
  EXPECT_EQ(sol.median_of(arr), 6);
  auto actual = sol.getStrongest(arr, expect.size());
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr{-7,22,17,3};
  vector<int> expect{22,17};
  EXPECT_EQ(sol.median_of(arr), 3);
  auto actual = sol.getStrongest(arr, expect.size());
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> arr;
  for(int i=0; i<10000; i++){
    arr.push_back(rand() % 1000);
  }
  vector<int> expect = arr;
  auto actual = sol.getStrongest(arr, expect.size());
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}

