#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words{"Hello", "Alaska", "Dad", "Peace"};
  vector<string> expect{"Alaska", "Dad"};

  EXPECT_EQ(sol.findWords(words), expect);
}

