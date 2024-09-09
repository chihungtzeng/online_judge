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

class Solution {
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
    auto cmp = [](const auto &a, const auto &b) { return a.size() < b.size(); };
    sort(words.begin(), words.end(), cmp);
    unordered_set<string> ans;
    TrieNode *root = new TrieNode();
    for (auto &word : words) {
      if (can_concat(root, word, ans)) {
        ans.insert(word);
      }
      insert_to_trie(root, word);
    }
    delete root;
    return vector(ans.begin(), ans.end());
  }
  void insert_to_trie(TrieNode *root, string &s) {
    TrieNode *cur = root;
    for (auto ch : s) {
      if (!cur->chs_[ch - 'a']) {
        cur->chs_[ch - 'a'] = new TrieNode();
      }
      cur = cur->chs_[ch - 'a'];
    }
    cur->eow_ = true;
  }
  vector<int> match_num_chars(TrieNode *root, string &s) {
    int n = 0;
    vector<int> ret;
    TrieNode *cur = root;
    for (auto ch : s) {
      if (!cur->chs_[ch - 'a']) return ret;
      cur = cur->chs_[ch - 'a'];
      n++;
      if (cur->eow_) ret.push_back(n);
    }
    return ret;
  }
  bool can_concat(TrieNode *root, string &s, unordered_set<string>& ans) {
    auto lens = match_num_chars(root, s);
    if (lens.empty()) return false;
    for (auto nchar : lens) {
      if (nchar == s.size()) return true;

      string t = s.substr(nchar, s.size());
      if (ans.find(t) != ans.end()){
        return true;
      }
      if (can_concat(root, t, ans)) {
        return true;
      }
    }
    return false;
  }
};
