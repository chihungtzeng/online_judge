#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  TweetCounts* obj = new TweetCounts();
  obj->recordTweet("tweet3", 0);
  obj->recordTweet("tweet3", 60);
  obj->recordTweet("tweet3", 10);
  auto actual1 = obj->getTweetCountsPerFrequency("minute", "tweet3", 0, 59);
  vector<int> expect1{2};
  EXPECT_EQ(expect1, actual1);
  auto actual2 = obj->getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
  vector<int> expect2{2, 1};
  EXPECT_EQ(expect2, actual2);
  obj->recordTweet("tweet3", 120);

  auto actual3 = obj->getTweetCountsPerFrequency("hour", "tweet3", 0, 210);
  vector<int> expect3{4};
  EXPECT_EQ(expect3, actual3);
  delete obj;
}

