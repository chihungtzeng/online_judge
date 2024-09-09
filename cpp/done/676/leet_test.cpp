#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  MagicDictionary *obj = new MagicDictionary();
  vector<string> dict{"hello", "leetcode"};
  obj->buildDict(dict);
  EXPECT_EQ(obj->search("hello"), false);
  EXPECT_EQ(obj->search("hhllo"), true);
  EXPECT_EQ(obj->search("hell"), false);
  EXPECT_EQ(obj->search("leetcoded"), false);
  delete obj;
}

TEST(kk, t2) {
  MagicDictionary *obj = new MagicDictionary();
  vector<string> dict{"hello", "leetcode", "hallo"};
  obj->buildDict(dict);
  EXPECT_EQ(obj->search("hello"), true);
  EXPECT_EQ(obj->search("hallo"), true);
  delete obj;
}

