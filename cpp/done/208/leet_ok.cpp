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

  /** Returns if the word is in the trie. */
  bool search(string word);

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix);
  Trie* match(const string& w);
  bool is_word_;
};

Trie::~Trie() {
  for (size_t i = 0; i < 26; i++) {
    if (keys_[i]) {
      delete keys_[i];
    }
  }
}

void Trie::insert(string w) {
  auto ch = w[0];
  auto pos = ch - 'a';
  auto suffix = w.substr(1, w.size());
  if (keys_[pos] == nullptr) {
    keys_[pos] = new Trie();
  }
  if (suffix.empty()) {
    keys_[pos]->is_word_ = true;
  } else {
    keys_[pos]->insert(suffix);
  }
}

Trie* Trie::match(const string& w) {
  auto ch = w[0];
  auto pos = ch - 'a';
  if (w.size() == 1) {
    return keys_[pos];
  } else if (keys_[pos] == nullptr) {
    return nullptr;
  } else {
    return keys_[pos]->match(w.substr(1, w.size()));
  }
}

bool Trie::search(string w) {
  auto* trie = match(w);
  if (!trie) {
    return false;
  }
  return trie->is_word_;
}

bool Trie::startsWith(string w) {
  auto* trie = match(w);
  return bool(trie);
}
