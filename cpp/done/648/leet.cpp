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
 public:
  bool eow_;
  vector<TrieNode *> chs_;
  TrieNode() : eow_(false), chs_(26) {}
  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      if (chs_[i]) delete chs_[i];
    }
  }
};

class Solution {
 public:
  string replaceWords(vector<string> &dict, string sentence) {
    TrieNode *root = buildTrie(dict);
    string ret;
    TrieNode *cur = root;
    bool match = false;
    bool start_matching = true;
    for (auto ch : sentence) {
      if (ch == ' ') {
        match = false;
        cur = root;
        start_matching = true;
      }
      if (match) {
        continue;
      }

      if ('a' <= ch && ch <= 'z' && start_matching && cur->chs_[ch - 'a']) {
        cur = cur->chs_[ch - 'a'];
        match = cur->eow_;
      } else if ('a' <= ch && ch <= 'z' && start_matching &&
                 !cur->chs_[ch - 'a']) {
        start_matching = false;
      }
      ret.push_back(ch);
    }
    delete root;
    return ret;
  }
  TrieNode *buildTrie(vector<string> &dict) {
    TrieNode *root = new TrieNode();
    for (auto &w : dict) {
      TrieNode *cur = root;
      for (auto ch : w) {
        int idx = ch - 'a';
        if (!cur->chs_[idx]) {
          cur->chs_[idx] = new TrieNode();
        }
        cur = cur->chs_[idx];
      }
      cur->eow_ = true;
    }
    return root;
  }
};
