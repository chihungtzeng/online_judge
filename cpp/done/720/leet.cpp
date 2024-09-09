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

struct Trie
{
  vector<Trie*> kids;
  bool eow;
  Trie() : kids(26), eow(false)
  {
  }
  void insert(string& s)
  {
    Trie* cur = this;
    for (auto ch : s)
    {
      int idx = ch - 'a';
      if (!cur->kids[idx])
      {
        cur->kids[idx] = new Trie();
      }
      cur = cur->kids[idx];
    }
    cur->eow = true;
  }
  ~Trie()
  {
    for (int i = 0; i < 26; i++)
    {
      if (kids[i])
        delete kids[i];
    }
  }
  bool match_all_prefix(string& s)
  {
    Trie* cur = this;
    for (auto ch : s)
    {
      int idx = ch - 'a';
      if (!cur->kids[idx])
        return false;
      cur = cur->kids[idx];
      if (!cur->eow)
        return false;
    }
    return true;
  }
};

class Solution
{
public:
  string longestWord(vector<string>& words)
  {
    Trie* root = new Trie();
    for (auto& word : words)
    {
      root->insert(word);
    }
    int best_len = 0;
    string ans;
    for (auto& word : words)
    {
      if (word.size() < best_len)
        continue;
      if (word.size() == best_len && word > ans)
      {
        continue;
      }
      string prefix = word.substr(0, word.size() - 1);
      if (root->match_all_prefix(prefix))
      {
        best_len = word.size();
        ans = word;
      }
    }
//    delete root;
    return ans;
  }
};
