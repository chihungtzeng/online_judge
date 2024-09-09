#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie
{
private:
  vector<Trie*> kids;
  bool eow;

public:
  /** Initialize your data structure here. */
  Trie() : kids(26), eow{ false }
  {
  }
  ~Trie()
  {
    for (int i = 0; i < 26; i++)
    {
      if (kids[i])
      {
        delete kids[i];
        kids[i] = nullptr;
      }
    }
  };

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    Trie* cur = this;
    for (auto ch : word)
    {
      ch -= 'a';
      if (!cur->kids[ch])
      {
        cur->kids[ch] = new Trie();
      }
      cur = cur->kids[ch];
    }
    cur->eow = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    Trie* cur = this;
    for (auto ch : word)
    {
      ch -= 'a';
      if (!cur->kids[ch])
      {
        return false;
      }
      cur = cur->kids[ch];
    }
    return cur->eow;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix)
  {
    Trie* cur = this;
    for (auto ch : prefix)
    {
      ch -= 'a';
      if (!cur->kids[ch])
      {
        return false;
      }
      cur = cur->kids[ch];
    }
    return true;
  }
};

