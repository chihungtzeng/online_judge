#include <glog/logging.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <memory>
#include <queue>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

std::unordered_map<string, int> g_mask_to_int;
int g_mask_nums;

class Word {
public:
  int32_t idx_;
  int32_t wlen_;
  int32_t dist_;
  bool visited = false;
  string word_;
  vector<int> nbrs_;
  Word() = default;
  Word(const int idx, const string &w) : idx_(idx), dist_(~0u), word_(w) {
    wlen_ = word_.length();
    gen_nbrs();
  }
  void gen_nbrs() {
    nbrs_.reserve(wlen_);

    auto s = word_;
    for (uint32_t i = 0; i < wlen_; i++) {
      s[i] = '*';
      if (g_mask_to_int.find(s) == g_mask_to_int.end())
      {
        g_mask_to_int[s] = g_mask_nums;
        g_mask_nums++;
      }
      nbrs_.push_back(g_mask_to_int[s]);
      s[i] = word_[i];
    }
  }
};
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    sort(wordList.begin(), wordList.end());
    if (!binary_search(wordList.begin(), wordList.end(), endWord)) {
      return 0;
    }
    g_mask_to_int.clear();
    g_mask_nums = 0;
    auto it = lower_bound(wordList.begin(), wordList.end(), endWord);
    auto target_idx = distance(wordList.begin(), it);

    vector<Word> words;
    words.reserve(wordList.size());
    for (uint32_t i = 0; i < wordList.size(); i++) {
      words.emplace_back(Word(i, wordList[i]));
    }

    map<int, vector<int>> mask_to_word_idx;
    for (int i = 0, nwords = wordList.size(); i < nwords; i++) {
      for (auto &mask_idx : words[i].nbrs_) {
        mask_to_word_idx[mask_idx].push_back(words[i].idx_);
      }
    }

    queue<int> q;
    Word begin_word{-1, beginWord};
    for (auto &mask : begin_word.nbrs_) {
      for (auto idx : mask_to_word_idx[mask]) {
        words[idx].dist_ = 1;
        words[idx].visited = true;
        q.push(idx);
      }
    }

    while (!q.empty()) {
      auto idx = q.front();
      q.pop();
      for (auto &mask : words[idx].nbrs_) {
        for (auto nbr_idx : mask_to_word_idx[mask]) {
          if (words[nbr_idx].visited) {
            continue;
          }
          words[nbr_idx].dist_ = 1 + words[idx].dist_;
          words[nbr_idx].visited = true;
          q.push(nbr_idx);
        }
      }
    }
    return words[target_idx].dist_ + 1;
  }
};
