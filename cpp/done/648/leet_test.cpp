#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> dict = {"cat","bat","rat"};
  string sentence = "the cattle was rattled by the battery";

  EXPECT_EQ(sol.replaceWords(dict, sentence), "the cat was rat by the bat");
}

TEST(kk, t2) {
  Solution sol;
  vector<string> dict = {"a", "aa", "aaa", "aaaa"};

  string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";

  EXPECT_EQ(sol.replaceWords(dict, sentence), "a a a a a a a a bbb baba a");

}

