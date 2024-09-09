#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  AuthenticationManager* obj = new AuthenticationManager(5);
  obj->renew("aaa", 1);
  obj->generate("aaa", 2);
  EXPECT_EQ(obj->countUnexpiredTokens(6), 1);
  obj->generate("bbb", 7);
  obj->renew("aaa", 8);
  obj->renew("bbb", 10);
  EXPECT_EQ(obj->countUnexpiredTokens(15), 0);
  delete obj;
}

