#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
Codec codec;
  vector<string> strs{"hello", "world", "", "I", "am,", "join"};
  string s = codec.encode(strs);
  LOG(INFO) << s;
  auto actual = codec.decode(s);
  LOG(INFO) << actual;
  EXPECT_EQ(actual, strs);

}

