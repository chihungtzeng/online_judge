#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TrieNode {
  bool eow;
  vector<TrieNode*> chars;
  TrieNode() : eow(false), chars(26, nullptr) {}
  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      if (chars[i]) {
        delete chars[i];
        chars[i] = nullptr;
      }
    }
  }
};

class Solution {
 public:
  int rows_, cols_;
  const vector<pair<int, int>> offsets_{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    rows_ = board.size();
    if (rows_ == 0) return {};
    cols_ = board[0].size();
    if (cols_ == 0) return {};

    TrieNode* root = new TrieNode();

    for (auto& word : words) {
      build_trie(root, word);
    }
    unordered_set<string> rset;
    string cur_word;
    for (int r = 0; r < rows_; r++) {
      for (int c = 0; c < cols_; c++) {
        dfs(board, r, c, root, rset, cur_word);
      }
    }

    delete root;
    vector<string> ret;
    for (const auto& word : rset) {
      ret.emplace_back(word);
    }
    return ret;
  }

  void build_trie(TrieNode* root, string& word) {
    TrieNode* cur = root;
    for (auto ch : word) {
      auto idx = ch - 'a';
      if (!cur->chars[idx]) {
        cur->chars[idx] = new TrieNode();
      }
      cur = cur->chars[idx];
    }
    cur->eow = true;
  }

  void dfs(vector<vector<char>>& board, int r, int c, TrieNode* root,
           unordered_set<string>& rset, string& cur_word) {
    auto ch = board[r][c];
    if (!root->chars[ch - 'a']) {
      return;
    }
    cur_word.push_back(ch);
    if (root->chars[ch - 'a']->eow) {
      rset.insert(cur_word);
    }
    board[r][c] = '#';
    for (const auto& offset : offsets_) {
      int r1 = r + offset.first;
      int c1 = c + offset.second;
      if (0 <= r1 && r1 < rows_ && 0 <= c1 && c1 < cols_ &&
          board[r1][c1] != '#') {
        dfs(board, r1, c1, root->chars[ch - 'a'], rset, cur_word);
      }
    }
    board[r][c] = ch;
    cur_word.pop_back();
  }
};
