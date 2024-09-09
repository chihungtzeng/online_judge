#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.mergeAlternately("abc", "pqr"), "apbqcr");
  EXPECT_EQ(sol.mergeAlternately("ab", "pqrs"), "apbqrs");
  EXPECT_EQ(sol.mergeAlternately("abcd", "pq"), "apbqcd");
}

