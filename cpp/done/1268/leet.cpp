#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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
  string word_;
  Trie() : chs_(26, nullptr), eow_(false) {}

  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (chs_[i]) delete chs_[i];
    }
  }
  void insert(string& s) {
    Trie* root = this;
    for (auto ch : s) {
      int idx = ch - 'a';
      if (!root->chs_[idx]) {
        root->chs_[idx] = new Trie();
      }
      root = root->chs_[idx];
    }
    root->eow_ = true;
    root->word_ = s;
  }
};

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products,
                                           string searchWord) {
    Trie* root = new Trie();
    for (auto& p : products) {
      root->insert(p);
    }
    Trie* cur = root;
    vector<vector<string>> ans;
    for (auto ch : searchWord) {
      int idx = ch - 'a';
      if (cur) {
        cur = cur->chs_[idx];
      }
      ans.emplace_back(find_words(cur));
    }
    delete root;
    return ans;
  }
  vector<string> find_words(Trie* root) {
    vector<string> ans;
    if (!root) return ans;
    vector<Trie*> q;
    q.push_back(root);
    while (!q.empty()) {
      Trie* cur = q.back();
      q.pop_back();
      if (cur->eow_) {
        ans.push_back(cur->word_);
        if (ans.size() == 3) return ans;
      }
      for (int i = 25; i >= 0; i--) {
        if (cur->chs_[i]) {
          q.push_back(cur->chs_[i]);
        }
      }
    }
    // LOG(INFO) << ans;
    return ans;
  }
};
