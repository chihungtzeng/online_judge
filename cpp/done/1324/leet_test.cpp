#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "HOW ARE YOU";
  vector<string> expect{"HAY","ORO","WEU"};
  EXPECT_EQ(sol.printVertically(s), expect);
}

TEST(kk, t2) {
  Solution sol;
  string s = "TO BE OR NOT TO BE";
  vector<string> expect{"TBONTB","OEROOE","   T"};
  EXPECT_EQ(sol.printVertically(s), expect);
}

TEST(kk, t3) {
  Solution sol;
  string s = "CONTEST IS COMING";
  vector<string> expect{"CIC","OSO","N M","T I","E N","S G","T"};
  EXPECT_EQ(sol.printVertically(s), expect);
}

