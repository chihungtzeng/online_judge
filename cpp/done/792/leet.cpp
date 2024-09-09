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

struct Trie {
  vector<Trie*> chs_;
  int eow_;
  Trie() : chs_(26), eow_(0) {}
  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (chs_[i]) delete chs_[i];
    }
  }
};

class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    Trie* root = new Trie();
    for (auto& w : words) {
      buildTrie(root, w);
    }
    auto ret = helper(root, S, 0);
    delete root;
    return ret;
  }
  int helper(Trie* root, string& s, int pos) {
    int ret = root->eow_;
    for (int i = 0; i < 26; i++) {
      if (!root->chs_[i]) continue;
      int next_pos = s.find(i + 'a', pos);
      if (next_pos != string::npos) {
        ret += helper(root->chs_[i], s, next_pos + 1);
      }
    }
    return ret;
  }
  void buildTrie(Trie* root, string& s) {
    Trie* cur = root;
    for (auto ch : s) {
      if (!cur->chs_[ch - 'a']) {
        cur->chs_[ch - 'a'] = new Trie();
      }
      cur = cur->chs_[ch - 'a'];
    }
    cur->eow_ += 1;
  }
};
