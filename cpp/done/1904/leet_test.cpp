#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string startTime = "12:01", finishTime = "12:44";
  EXPECT_EQ(sol.numberOfRounds(startTime, finishTime), 1);
}

TEST(kk, t2) {
  Solution sol;
  string startTime = "20:00", finishTime = "06:00";
  EXPECT_EQ(sol.numberOfRounds(startTime, finishTime), 40);
}

TEST(kk, t3) {
  Solution sol;
  string startTime = "00:00", finishTime = "23:59";
  EXPECT_EQ(sol.numberOfRounds(startTime, finishTime), 95);
}

TEST(kk, t4) {
  Solution sol;
  string startTime = "12:14", finishTime = "12:13";
  EXPECT_EQ(sol.numberOfRounds(startTime, finishTime), 95);
}

TEST(kk, t5) {
  Solution sol;
  string startTime = "00:47", finishTime = "00:57";
  EXPECT_EQ(sol.numberOfRounds(startTime, finishTime), 0);
}

