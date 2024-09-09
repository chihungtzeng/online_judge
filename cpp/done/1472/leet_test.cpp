#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  BrowserHistory* obj = new BrowserHistory("leetcode.com");
  obj->visit("google.com");
  obj->visit("facebook.com");
  obj->visit("youtube.com");
  EXPECT_EQ(obj->back(1), "facebook.com");
  EXPECT_EQ(obj->back(1), "google.com");
  EXPECT_EQ(obj->forward(1), "facebook.com");
  obj->visit("linkedin.com");
  EXPECT_EQ(obj->forward(2), "linkedin.com");
  EXPECT_EQ(obj->back(2), "google.com");
  EXPECT_EQ(obj->back(7), "leetcode.com");

  delete obj;
}

