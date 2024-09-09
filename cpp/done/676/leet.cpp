#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TrieNode {
  vector<TrieNode *> chs_;
  bool eow_;
  TrieNode() : chs_(26), eow_(false) {}
  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      if (chs_[i]) delete chs_[i];
    }
  }
};

class MagicDictionary {
 public:
  /** Initialize your data structure here. */
  TrieNode *root_;
  MagicDictionary() : root_(nullptr) {}
  ~MagicDictionary() {
    if (root_) delete root_;
  }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    if (root_) delete root_;
    root_ = new TrieNode();
    for (auto &word : dict) {
      buildTrie(root_, word);
    }
  }

  void buildTrie(TrieNode *root, string &s) {
    TrieNode *cur = root;
    for (auto ch : s) {
      int idx = ch - 'a';
      if (!cur->chs_[idx]) {
        cur->chs_[idx] = new TrieNode();
      }
      cur = cur->chs_[idx];
    }
    cur->eow_ = true;
  }

  /** Returns if there is any word in the trie that equals to the given word
   * after modifying exactly one character */
  bool search(string word) {
    for (int i = word.size() - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        char ch = 'a' + j;
        if (ch == word[i]) {
          continue;
        }
        swap(word[i], ch);
        if (_search(word)) {
          return true;
        }
        swap(word[i], ch);
      }
    }
    return false;
  }
  bool _search(string &word) {
    TrieNode *cur = root_;
    for (auto ch : word) {
      if (cur->chs_[ch - 'a']) {
        cur = cur->chs_[ch - 'a'];
      } else {
        return false;
      }
    }
    return cur->eow_;
  }
};
