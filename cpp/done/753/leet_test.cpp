#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t0) {
  string s = "abcde";
  string t = s.substr(5);
  s.push_back('z');
  LOG(INFO) << "t is >>" << t << "<<";
  LOG(INFO) << s;
  s.pop_back();
  LOG(INFO) << s;
  LOG(INFO) << string(3, '0');
}


TEST(kk, t1) {
  Solution sol;
  auto ans = sol.crackSafe(1, 2);
  EXPECT_EQ(ans, "01");
}

TEST(kk, t2) {
  Solution sol;
  auto ans = sol.crackSafe(2, 2);
  EXPECT_EQ(ans, "00110");
}

TEST(kk, t3) {
  Solution sol;
  LOG(INFO) << sol.crackSafe(3, 7);
}

