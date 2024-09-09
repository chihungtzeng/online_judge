#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string S;
  int K;

  S = "5F3Z-2e-9-w", K = 4;
  EXPECT_EQ(sol.licenseKeyFormatting(S, K), "5F3Z-2E9W");

  S = "2-5g-3-J", K = 2;
  EXPECT_EQ(sol.licenseKeyFormatting(S, K), "2-5G-3J");

  S = "---", K = 3;
  EXPECT_EQ(sol.licenseKeyFormatting(S, K), "");

  S = "", K = 3;
  EXPECT_EQ(sol.licenseKeyFormatting(S, K), "");
}

