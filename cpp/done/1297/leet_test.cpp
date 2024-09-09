#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string s;
  int maxLetters = 2, minSize = 3, maxSize = 4;

  s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4;
  EXPECT_EQ(sol.maxFreq(s, maxLetters, minSize,maxSize), 2);
   s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3;
  EXPECT_EQ(sol.maxFreq(s, maxLetters, minSize,maxSize), 2);

   s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3;
  EXPECT_EQ(sol.maxFreq(s, maxLetters, minSize,maxSize), 3);

  s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3;
  EXPECT_EQ(sol.maxFreq(s, maxLetters, minSize,maxSize), 0);

}

TEST(kk, t2){
  Solution sol;
  string s;
  int maxLetters = 2, minSize = 3, maxSize = 4;
  for(int i=0; i<100000; i++){
    s.push_back(i % 6 + 'a');
  }
  maxLetters = 3, minSize = 10, maxSize=20;
  sol.maxFreq(s, maxLetters, minSize,maxSize);
}
