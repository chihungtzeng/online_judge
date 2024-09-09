#include <glog/logging.h>
#include <algorithm>
#include <map>
#include <memory>
#include <queue>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

class Word {
public:
  int32_t idx_;
  int32_t wlen_;
  int32_t dist_;
  bool visited = false;
  string word_;
  vector<string> masked_nbrs_;
  vector<int> parents_;
  Word() = default;
  Word(const int idx, const string &w) : idx_(idx), dist_(~0u), word_(w) {
    wlen_ = word_.length();
    gen_nbrs();
  }
  void gen_nbrs() {
    masked_nbrs_.reserve(wlen_);

    auto s = word_;
    for (uint32_t i = 0; i < wlen_; i++) {
      s[i] = '*';
      masked_nbrs_.push_back(s);
      s[i] = word_[i];
    }
  }
};
class Solution {
public:
  int target_idx_ = 0;
  vector<Word> words_;
  string beginWord_;

  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
  {
    beginWord_ = beginWord;
    if (ladderLength(beginWord, endWord, wordList) == 0) {
      return vector<vector<string>>{};
    }
    auto paths = findLadders(target_idx_);
    for(auto &vs: paths)
    {
      std::reverse(vs.begin(), vs.end());
    }
    return paths;
  }

  vector<vector<string>> findLadders(int cur_idx)
  {
    if (words_[cur_idx].dist_ == 1)
    {
      return vector<vector<string>>{{words_[cur_idx].word_, beginWord_}};
    }
    vector<vector<string>> ret;
    for(const auto& parent: words_[cur_idx].parents_) {
      for(auto& path: findLadders(parent)){
        vector<string> cur_path{words_[cur_idx].word_};
        cur_path.insert(cur_path.end(), path.begin(), path.end());
        ret.emplace_back(cur_path);
      }
    }
    return ret;
  }

  int ladderLength(const string& beginWord, const string& endWord, vector<string> &wordList) {
    sort(wordList.begin(), wordList.end());
    if (!binary_search(wordList.begin(), wordList.end(), endWord)) {
      return 0;
    }
    auto it = lower_bound(wordList.begin(), wordList.end(), endWord);
    target_idx_ = distance(wordList.begin(), it);
    words_.reserve(wordList.size());
    for (uint32_t i = 0; i < wordList.size(); i++) {
      words_.emplace_back(Word(i, wordList[i]));
    }

    map<string, vector<int>> mask_to_word_idx;
    for (int i = 0, nwords = wordList.size(); i < nwords; i++) {
      for (auto &mask : words_[i].masked_nbrs_) {
        mask_to_word_idx[mask].push_back(words_[i].idx_);
      }
    }

    queue<int> q;
    Word begin_word{-1, beginWord};
    for (auto &mask : begin_word.masked_nbrs_) {
      for (auto idx : mask_to_word_idx[mask]) {
        words_[idx].dist_ = 1;
        words_[idx].visited = true;
        words_[idx].parents_.emplace_back(-1);
        q.push(idx);
      }
    }

    while (!q.empty()) {
      auto idx = q.front();
      q.pop();
      for (auto &mask : words_[idx].masked_nbrs_) {
        for (auto nbr_idx : mask_to_word_idx[mask]) {
          if (!words_[nbr_idx].visited) {
            words_[nbr_idx].dist_ = 1 + words_[idx].dist_;
            words_[nbr_idx].visited = true;
            q.push(nbr_idx);
          }
          if (words_[nbr_idx].dist_ == 1 + words_[idx].dist_) {
            words_[nbr_idx].parents_.emplace_back(idx);
          }
        }
      }
    }
    return words_[target_idx_].dist_ + 1;
  }
};
