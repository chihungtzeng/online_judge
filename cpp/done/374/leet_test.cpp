#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

#define ANS 6

int guess(int num) {
  if (num < ANS) {
    return 1;
  } else if (num == ANS) {
    return 0;
  } else {
    return -1;
  }
}

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.guessNumber(10), ANS);
}

