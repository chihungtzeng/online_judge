#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words{"step", "steps", "stripe", "stepple"};

  EXPECT_EQ(sol.shortestCompletingWord("1s3 PSt", words), "steps");
}

TEST(kk, t2) {
  Solution sol;
  vector<string> words{"looks", "pest", "stew", "show"};

  EXPECT_EQ(sol.shortestCompletingWord("1s3 456", words), "pest");
}

