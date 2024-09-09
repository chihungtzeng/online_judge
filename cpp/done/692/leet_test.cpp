#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> expect{"i", "love"};

  EXPECT_EQ(sol.topKFrequent(words, 2), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
  vector<string> expect{"the", "is", "sunny", "day"};

  EXPECT_EQ(sol.topKFrequent(words, 4), expect);
}

