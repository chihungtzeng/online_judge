#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
  EXPECT_EQ(sol.minJumps(arr), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> arr = {7};
  EXPECT_EQ(sol.minJumps(arr), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> arr = {7,6,9,6,9,6,9,7};
  EXPECT_EQ(sol.minJumps(arr), 1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> arr = {6,1,9};
  EXPECT_EQ(sol.minJumps(arr), 2);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> arr = {11,22,7,7,7,7,7,7,7,22,13};
  EXPECT_EQ(sol.minJumps(arr), 3);
}

#if 1
TEST(kk, t6) {
  Solution sol;
  vector<int> arr;
  for(int i=0; i<50000; i++){
    arr.push_back(7);
  }
  arr.push_back(11);
  EXPECT_EQ(sol.minJumps(arr), 2);
}
#endif
