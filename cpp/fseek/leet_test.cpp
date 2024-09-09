#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  FR fr("../text.txt");
  char buf[5] = {};
  fr.read(buf, 4);
  LOG(INFO) << buf;

}

