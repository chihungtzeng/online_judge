#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  vector<int> blacklist;
  int N = 1;
  Solution* obj = new Solution(N, blacklist);
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(obj->pick(), 0);
  }
  delete obj;
}

TEST(kk, t2) {
  vector<int> blacklist;
  int N = 2;
  Solution* obj = new Solution(N, blacklist);
  int one = 0, zero = 0;
  for (int i = 0; i < 10; i++) {
    int p = obj->pick();
    if (p == 0) zero++;
    if (p == 1) one++;
  }
  EXPECT_TRUE(zero > 0);
  EXPECT_TRUE(one > 0);
  delete obj;
}

TEST(kk, t3) {
  vector<int> blacklist{1};
  int N = 3;
  Solution* obj = new Solution(N, blacklist);
  int one = 0, zero = 0, two;
  for (int i = 0; i < 10; i++) {
    int p = obj->pick();
    if (p == 0) zero++;
    if (p == 1) one++;
    if (p == 2) two++;
  }
  EXPECT_TRUE(zero > 0);
  EXPECT_TRUE(one == 0);
  EXPECT_TRUE(two > 0);
  delete obj;
}

TEST(kk, t4) {
  vector<int> blacklist{2};
  int N = 4;
  Solution* obj = new Solution(N, blacklist);
  int one = 0, zero = 0, two = 0, three = 0;
  for (int i = 0; i < 200000; i++) {
    int p = obj->pick();
    if (p == 0) zero++;
    if (p == 1) one++;
    if (p == 2) two++;
    if (p == 3) three++;
  }
  EXPECT_TRUE(zero > 0);
  EXPECT_TRUE(one > 0);
  EXPECT_TRUE(two == 0);
  EXPECT_TRUE(three > 0);
  delete obj;
}

TEST(kk, t5) {
  vector<int> blacklist{0, 1};
  int N = 3;
  Solution* obj = new Solution(N, blacklist);
  int one = 0, zero = 0, two = 0;
  for (int i = 0; i < 200000; i++) {
    int p = obj->pick();
    if (p == 0) zero++;
    if (p == 1) one++;
    if (p == 2) two++;
  }
  EXPECT_TRUE(zero == 0);
  EXPECT_TRUE(one == 0);
  EXPECT_TRUE(two == 200000);
  delete obj;
}

