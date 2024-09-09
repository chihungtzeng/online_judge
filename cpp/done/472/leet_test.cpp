#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words{"cat", "cats",        "catsdogcats",
                       "dog", "dogcatsdog",  "hippopotamuses",
                       "rat", "ratcatdogcat"};
  vector<string> expect{"catsdogcats", "dogcatsdog", "ratcatdogcat"};
  auto actual = sol.findAllConcatenatedWordsInADict(words);
  sort(expect.begin(), expect.end());
  sort(actual.begin(), actual.end());

  EXPECT_EQ(actual, expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> words{""};
  auto actual = sol.findAllConcatenatedWordsInADict(words);
  EXPECT_EQ(actual.size(), 0);
}

string gen_string(int n){
  string s;
  for(int i=0;i<n;i++){
    s.push_back('a');
  }
  return s;
}

TEST(kk, t3) {
  Solution sol;
  vector<string> words;
  for(int i=1; i<800; i++){
    words.emplace_back(gen_string(i));
  }
  vector<string> expect(words.begin() + 1, words.end());
  auto actual = sol.findAllConcatenatedWordsInADict(words);
  sort(expect.begin(), expect.end());
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

