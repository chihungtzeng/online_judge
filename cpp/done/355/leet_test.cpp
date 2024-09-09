#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Twitter* obj = new Twitter();
  obj->postTweet(1, 5);

  LOG(INFO) << "id_posts_[1] size: " << obj->id_posts_[1].size();
  vector<int> expect5{5};
  EXPECT_EQ(obj->getNewsFeed(1), expect5);
  obj->follow(1, 2);
  obj->postTweet(2, 6);
  vector<int> expect{6, 5};
  EXPECT_EQ(obj->getNewsFeed(1), expect);
  obj->unfollow(1, 2);
  EXPECT_EQ(obj->getNewsFeed(1), expect5);
  delete obj;
}

TEST(kk, t2) {
  Twitter* obj = new Twitter();
  obj->postTweet(1, 5);
  obj->postTweet(1, 3);

  vector<int> expect{3, 5};
  EXPECT_EQ(obj->getNewsFeed(1), expect);
  delete obj;
}

TEST(kk, t3) {
  Twitter* obj = new Twitter();
  obj->postTweet(1, 5);

  obj->follow(1, 1);
  vector<int> expect{5};
  EXPECT_EQ(obj->getNewsFeed(1), expect);
  delete obj;
}

