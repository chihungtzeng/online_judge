#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
 private:
  vector<Trie*> keys_;

 public:
  /** Initialize your data structure here. */
  Trie() : keys_{26}, is_word_{false} {}
  ~Trie();

  /** Inserts a word into the trie. */
  void insert(string word);
  void insert(const char* word, const int wsize);

  /** Returns if the word is in the trie. */
  bool search(string word);

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix);
  Trie* match(const char* w, const int wsize);
  bool is_word_;
};

Trie::~Trie() {
  for (size_t i = 0; i < 26; i++) {
    if (keys_[i]) {
      delete keys_[i];
    }
  }
}

void Trie::insert(string w) { insert(w.c_str(), w.size()); }

void Trie::insert(const char* w, const int wsize) {
  auto ch = w[0];
  auto pos = ch - 'a';
  if (keys_[pos] == nullptr) {
    keys_[pos] = new Trie();
  }
  if (wsize == 1) {
    keys_[pos]->is_word_ = true;
  } else {
    keys_[pos]->insert(w + 1, wsize - 1);
  }
}

Trie* Trie::match(const char* w, const int wsize) {
  auto ch = w[0];
  auto pos = ch - 'a';
  if (wsize == 1) {
    return keys_[pos];
  } else if (keys_[pos] == nullptr) {
    return nullptr;
  } else {
    return keys_[pos]->match(w + 1, wsize - 1);
  }
}

bool Trie::search(string w) {
  auto* trie = match(w.c_str(), w.size());
  if (!trie) {
    return false;
  }
  return trie->is_word_;
}

bool Trie::startsWith(string w) {
  auto* trie = match(w.c_str(), w.size());
  return bool(trie);
}
