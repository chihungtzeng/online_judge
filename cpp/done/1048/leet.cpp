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
  int sid_;
  Trie() : chs_(26), eow_(false), sid_(-1) {}
  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (chs_[i]) {
        delete chs_[i];
        chs_[i] = nullptr;
      }
    }
  }
};

class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    Trie* root = new Trie();
    const int n = words.size();
    for (int i = 0; i < n; i++) {
      insert_to_trie(root, words[i], i);
    }
    vector<vector<int>> nbrs(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < words[i].size(); j++) {
        string s2 = words[i].substr(0, j) + words[i].substr(j + 1);
        int nbr = find(root, s2);
        if (nbr < 0) continue;
        nbrs[i].push_back(nbr);
      }
    }
    vector<int> indegrees(n);
    for (int i = 0; i < n; i++) {
      for (auto nbr : nbrs[i]) {
        indegrees[nbr] += 1;
      }
    }
    deque<int> q;
    vector<int> depth(n);
    for (int i = 0; i < n; i++) {
      if (indegrees[i] == 0) {
        depth[i] = 0;
        q.push_back(i);
      }
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      for (auto nbr : nbrs[cur]) {
        indegrees[nbr] -= 1;
        if (indegrees[nbr] == 0) {
          depth[nbr] = depth[cur] + 1;
          q.push_back(nbr);
        }
      }
    }
    return *max_element(depth.begin(), depth.end()) + 1;
    delete root;
  }
  void insert_to_trie(Trie* root, string& s, int sid) {
    for (auto ch : s) {
      if (!root->chs_[ch - 'a']) {
        root->chs_[ch - 'a'] = new Trie();
      }
      root = root->chs_[ch - 'a'];
    }
    root->eow_ = true;
    root->sid_ = sid;
  }
  int find(Trie* root, string& s) {
    for (auto ch : s) {
      if (root->chs_[ch - 'a']) {
        root = root->chs_[ch - 'a'];
      } else {
        return -1;
      }
    }
    if (root->eow_) return root->sid_;
    return -1;
  }
};
