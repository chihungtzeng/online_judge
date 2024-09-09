#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  string s="12345";
  bool done = false;
  do {
    LOG(INFO) << s;
  } while (next_permutation(s.begin(), s.end()));
}

