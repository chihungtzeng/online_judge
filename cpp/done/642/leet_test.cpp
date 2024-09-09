#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  vector<string> sentences = {"i love you", "island", "ironman",
                              "i love leetcode"};
  vector<int> times = {5, 3, 2, 2};
  AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);

  vector<string> expect1 = {"i love you", "island", "i love leetcode"};
  EXPECT_EQ(obj->input('i'), expect1);

  vector<string> expect2 = {"i love you", "i love leetcode"};
  EXPECT_EQ(obj->input(' '), expect2);

  vector<string> expect_empty;
  EXPECT_EQ(obj->input('a'), expect_empty);

  EXPECT_EQ(obj->input('#'), expect_empty);
  delete obj->root_;
  delete obj;
}

TEST(kk, t2) {
  vector<string> expect_empty;
  vector<string> sentences = {"i love you", "island", "ironman",
                              "i love leetcode"};
  vector<int> times = {5, 3, 2, 2};
  AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);

  vector<string> expect1 = {"i love you", "island", "i love leetcode"};
  EXPECT_EQ(obj->input('i'), expect1);

  vector<string> expect2 = {"i love you", "i love leetcode"};
  EXPECT_EQ(obj->input(' '), expect2);

  EXPECT_EQ(obj->input('a'), expect_empty);
  EXPECT_EQ(obj->input('#'), expect_empty);
  vector<string> expect3 = {"i love you", "island", "i love leetcode"};
  EXPECT_EQ(obj->input('i'), expect3);
  vector<string> expect4 = {"i love you", "i love leetcode", "i a"};
  EXPECT_EQ(obj->input(' '), expect4);
  vector<string> expect5 = {"i a"};
  EXPECT_EQ(obj->input('a'), expect5);
  EXPECT_EQ(obj->input('#'), expect_empty);
  vector<string> expect6 = {"i love you", "island", "i a"};
  EXPECT_EQ(obj->input('i'), expect6);
  vector<string> expect7 = {"i love you", "i a", "i love leetcode"};
  EXPECT_EQ(obj->input(' '), expect7);

  vector<string> expect8 = {"i a"};
  EXPECT_EQ(obj->input('a'), expect8);

  EXPECT_EQ(obj->input('#'), expect_empty);

  delete obj->root_;
  delete obj;
}
