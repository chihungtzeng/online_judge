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
  bool eow_;
  Trie() : chs_(26), eow_(false) {}
  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (chs_[i]) delete chs_[i];
    }
  }
};

class Solution {
 public:
  string longestWord(vector<string>& words) {
    Trie* root = new Trie();
    for (auto& w : words) {
      build_trie(root, w);
    }
    string ret, cur;
    dfs(root, ret, cur);
    // delete root;
    return ret;
  }
  void build_trie(Trie* root, string& s) {
    Trie* cur = root;
    for (auto ch : s) {
      int idx = ch - 'a';
      if (!cur->chs_[idx]) {
        cur->chs_[idx] = new Trie();
      }
      cur = cur->chs_[idx];
    }
    cur->eow_ = true;
  }
  void dfs(Trie* root, string& ret, string& cur) {
    for (int i = 0; i < 26; i++) {
      if (root->chs_[i] && root->chs_[i]->eow_) {
        cur.push_back(i + 'a');
        if (cur.size() > ret.size()) ret = cur;
        dfs(root->chs_[i], ret, cur);
        cur.pop_back();
      }
    }
  }
};
