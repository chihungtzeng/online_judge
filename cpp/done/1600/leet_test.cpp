#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  ThroneInheritance* obj = new ThroneInheritance("king");
  obj->birth("king", "andy");
  obj->birth("king", "bob");
  obj->birth("king", "catherine");
  obj->birth("andy", "matthew");
  obj->birth("bob", "alex");
  obj->birth("bob", "asha");
  vector<string> expect{"king", "andy", "matthew", "bob", "alex", "asha", "catherine"};
  EXPECT_EQ( obj->getInheritanceOrder(), expect);

  obj->death("bob");

  vector<string> expect2{"king", "andy", "matthew", "alex", "asha", "catherine"};
  EXPECT_EQ( obj->getInheritanceOrder(), expect2);
  delete obj;
}

