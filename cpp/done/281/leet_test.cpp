#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  vector<int> v1 = {1,2};
  vector<int> v2 = {3,4,5,6};
  ZigzagIterator i(v1, v2);
  while (i.hasNext()) cout << i.next();
}

