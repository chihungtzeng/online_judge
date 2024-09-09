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
  string content_;
  int freq_;
  unordered_map<char, Trie*> next_;

  Trie() : content_(""), freq_(0) {}
  ~Trie() {
    for (auto [_, ptr] : next_) {
      delete ptr;
    }
  }
};

class AutocompleteSystem {
 public:
  Trie* root_;
  string cur_sen_;
  Trie* cur_trie_;
  AutocompleteSystem(vector<string>& sentences, vector<int>& times)
      : root_(nullptr), cur_sen_("") {
    root_ = new Trie();
    int n = times.size();
    cur_trie_ = root_;
    for (int i = 0; i < n; i++) {
      insert_to_trie(root_, sentences[i], times[i]);
    }
  }

  void insert_to_trie(Trie* root, string& s, int freq) {
    for (auto ch : s) {
      auto it = root->next_.find(ch);
      if (it == root->next_.end()) {
        root->next_[ch] = new Trie();
      }
      root = root->next_[ch];
    }
    root->content_ = s;
    root->freq_ += freq;
  }

  vector<string> get_hot_sentences(char c) {
    vector<string> ans;
    if (!cur_trie_) return ans;

    if (cur_trie_->next_.find(c) == cur_trie_->next_.end()) {
      cur_trie_ = nullptr;
      return ans;
    }
    cur_trie_ = cur_trie_->next_[c];

    // get candidates
    vector<pair<int, string>> cans;
    deque<Trie*> q;
    q.push_back(cur_trie_);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop_front();
      if (!cur->content_.empty()) {
        cans.push_back({cur->freq_, cur->content_});
      }
      for (auto& [key, ptr] : cur->next_) {
        q.push_back(ptr);
      }
    }
    if (cans.empty()) return ans;
    auto cmp = [](const auto& a, const auto& b) {
      if (a.first != b.first)
        return a.first < b.first;
      else
        return a.second > b.second;
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)>
        pq(cans.begin(), cans.end(), cmp);
    while (ans.size() < 3 && !pq.empty()) {
      auto [freq, str] = pq.top();
      // LOG(INFO) << "str: " << str << " freq: " << freq;
      pq.pop();
      ans.emplace_back(str);
    }
    return ans;
  }

  vector<string> input(char c) {
    if (c == '#') {
      insert_to_trie(root_, cur_sen_, 1);
      cur_sen_ = "";
      cur_trie_ = root_;
      return {};
    } else {
      cur_sen_.push_back(c);
      return get_hot_sentences(c);
    }
  }
};

