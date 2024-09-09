#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string url = "https://leetcode.com/problems/design-tinyurl";
  string surl = sol.encode(url);
  LOG(INFO) << surl;
  EXPECT_EQ(sol.decode(surl), url);

  url = "http://tinyurl.com/4e9iAk";
  surl = sol.encode(url);
  LOG(INFO) << surl;
  EXPECT_EQ(sol.decode(surl), url);

  LOG(INFO) << sol.stol_;
}

