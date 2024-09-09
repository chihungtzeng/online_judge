#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string sentence1 = "My name is Haley", sentence2 = "My Haley";
  EXPECT_EQ(sol.areSentencesSimilar(sentence1, sentence2), true );
}

TEST(kk, t2) {
  Solution sol;
  string sentence1 = "of", sentence2 = "A lot of words";
  EXPECT_EQ(sol.areSentencesSimilar(sentence1, sentence2), false);
}

TEST(kk, t3) {
  Solution sol;
  string sentence1 = "Eating right now", sentence2 = "Eating";
  EXPECT_EQ(sol.areSentencesSimilar(sentence1, sentence2), true);
}

TEST(kk, t4) {
  Solution sol;
  string sentence1 = "Luky", sentence2 = "Lucccky";
  EXPECT_EQ(sol.areSentencesSimilar(sentence1, sentence2), false);
}

TEST(kk, t5) {
  Solution sol;
  string sentence1 = "Ogn WtWj HneS", sentence2 = "Ogn WtWj HneS";
  EXPECT_EQ(sol.areSentencesSimilar(sentence1, sentence2), true);
}

