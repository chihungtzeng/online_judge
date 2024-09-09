#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {

Trie* trie = new Trie();

trie->insert("apple");
EXPECT_TRUE(trie->search("apple"));   // returns true
EXPECT_FALSE(trie->search("app"));     // returns false
EXPECT_TRUE(trie->startsWith("app")); // returns true
trie->insert("app");
EXPECT_TRUE(trie->search("app"));     // returns true
delete trie;
}

