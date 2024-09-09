#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"
#include <climits>

#define BAD_VER 2

bool isBadVersion(int version) { return bool(version >= BAD_VER); }

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.firstBadVersion(INT_MAX), BAD_VER);
}

