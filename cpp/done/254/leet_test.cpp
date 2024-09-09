#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> expect;
  EXPECT_EQ(sol.getFactors(1), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> expect;
  EXPECT_EQ(sol.getFactors(37), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> expect{{2, 6}, {2, 2, 3}, {3, 4}};
  int n = 12;
  for(auto& arr: expect){
    sort(arr.begin(),arr.end());
  }
  sort(expect.begin(), expect.end());
  auto actual = sol.getFactors(n);
  for(auto& arr: actual){
    sort(arr.begin(),arr.end());
  }
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> expect{{2, 16},         {2, 2, 8}, {2, 2, 2, 4},
                             {2, 2, 2, 2, 2}, {2, 4, 4}, {4, 8}};

  for(auto& arr: expect){
    sort(arr.begin(),arr.end());
  }
  sort(expect.begin(), expect.end());
  auto actual = sol.getFactors(32);
  for(auto& arr: actual){
    sort(arr.begin(),arr.end());
  }
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> expect{{37, 37}};
  EXPECT_EQ(sol.getFactors(37 * 37), expect);
}

