#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  vector<int> w{1};
  Solution* obj = new Solution(w);
  int param_1 = obj->pickIndex();
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(param_1, 0);
  }
  delete obj;
}

TEST(kk, t2) {
  vector<int> w{1, 3};
  Solution* obj = new Solution(w);
  int n0 = 0, n1 = 1;
  int total = 1000;
  for (int i = 0; i < total; i++) {
    auto pick = obj->pickIndex();
    if (pick == 0)
      n0++;
    else
      n1++;
  }
  LOG(INFO) << "n0: " << n0 << " n1: " << n1 << " ratio: " << 1.0 * n1 / total;
  delete obj;
}

