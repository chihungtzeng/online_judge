#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  AllOne* allone = new AllOne();
  allone->inc("apple");
  allone->inc("lemon");
  allone->inc("lemon");

  allone->dump();

  delete allone;
}

