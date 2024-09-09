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
  bool eof_;
  Trie() : chs_(128), eof_(false){};
  ~Trie() {
    for (int i = 0; i < 128; i++) {
      if (chs_[i]) delete chs_[i];
    }
  }
  bool is_subdir(string& s) {
    Trie* root = this;
    for (int i = 0, n = s.size(); i < n; i++) {
      char ch = s[i];
      if (root->eof_ && i < n - 1 && s[i] == '/') {
        //LOG(INFO) << s << " : match a subdir at " << ch;
        return true;
      }
      if (!root->chs_[ch]) {
        //LOG(INFO) << s << " : cannot match a subdir at " << ch;
        return false;
      }
      //LOG(INFO) << s << " : go to next char from " << ch;
      root = root->chs_[ch];
    }
    return root->eof_;
  }
  void insert(string& s) {
    Trie* root = this;
    for (auto ch : s) {
      if (!root->chs_[ch]) {
        root->chs_[ch] = new Trie();
      }
      root = root->chs_[ch];
    }
    root->eof_ = true;
  }
};
class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    auto cmp = [](const auto& a, const auto& b) { return a.size() < b.size(); };
    sort(folder.begin(), folder.end(), cmp);
    Trie* root = new Trie();
    vector<string> ans;
    for (auto& s : folder) {
      if (!root->is_subdir(s)) {
        ans.push_back(s);
        root->insert(s);
      }
    }
    delete root;
    return ans;
  }
};
