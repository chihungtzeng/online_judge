#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> keyName = {"daniel", "daniel", "daniel", "luis",
                            "luis",   "luis",   "luis"},
                 keyTime = {"10:00", "10:40", "11:00", "09:00",
                            "11:00", "13:00", "15:00"};
  vector<string> expect{"daniel"};
  EXPECT_EQ(sol.alertNames(keyName, keyTime), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> keyName = {"alice", "alice", "alice", "bob",
                            "bob",   "bob",   "bob"},
                 keyTime = {"12:01", "12:00", "18:00", "21:00",
                            "21:20", "21:30", "23:00"};
  vector<string> expect{"bob"};
  EXPECT_EQ(sol.alertNames(keyName, keyTime), expect);
}
TEST(kk, t3) {
  Solution sol;
  vector<string> keyName = {"john", "john", "john"},
                 keyTime = {"23:58", "23:59", "00:01"};
  vector<string> expect;
  EXPECT_EQ(sol.alertNames(keyName, keyTime), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<string> keyName = {"leslie", "leslie", "leslie", "clare",
                            "clare",  "clare",  "clare"},
                 keyTime = {"13:00", "13:20", "14:00",
                            "18:00", "18:51", "19:30", "19:49"};
  vector<string> expect{"clare", "leslie"};
  EXPECT_EQ(sol.alertNames(keyName, keyTime), expect);
}

