#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;
#define DELETE_PTR 1

struct TrieNode
{
  vector<TrieNode*> kids{ 26, nullptr };
  int eow = -1;
  ~TrieNode()
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
};

class Solution
{
public:
  void insert_into_trie(TrieNode* root, string& s, int idx)
  {
    for (int i = s.size() - 1; i >= 0; i--)
    {
      int target = s[i] - 'a';
      if (!root->kids[target])
      {
        root->kids[target] = new TrieNode();
      }
      root = root->kids[target];
    }
    root->eow = idx;
  }

  vector<vector<int>> palindromePairs(vector<string>& words)
  {
    TrieNode* root = new TrieNode();
    int es_idx = -1;
    for (int i = 0; i < words.size(); i++)
    {
      if (words[i].empty())
      {
        es_idx = i;
      }
      else
      {
        insert_into_trie(root, words[i], i);
      }
    }
    vector<vector<int>> ans;
    ans.reserve(words.size() * words.size());

    if (es_idx >= 0)
    {
      for (int i = 0; i < words.size(); i++)
      {
        if (i == es_idx)
          continue;
        if (is_palindrom(words[i], 0, words[i].size() - 1))
        {
          ans.emplace_back(vector<int>{ i, es_idx });
          ans.emplace_back(vector<int>{ es_idx, i });
        }
      }
    }

    for (int i = 0; i < words.size(); i++)
    {
      if (!words[i].empty())
      {
        discover_ans(root, words[i], i, words, ans);
      }
    }
#ifdef DELETE_PTR
    delete root;
#endif
    return ans;
  }

  void discover_ans(TrieNode* root, string& s, int idx, vector<string>& words, vector<vector<int>>& ans)
  {
    TrieNode* cur = root;
    bool done = false;
    int j = 0;
    for (j = 0; j < s.size() && !done; j++)
    {
      if (cur->eow >= 0 && is_palindrom(s, j, s.size() - 1) && cur->eow != idx)
      {
        ans.emplace_back(vector<int>{ idx, cur->eow });
      }

      int target = s[j] - 'a';
      if (cur->kids[target] != nullptr)
      {
        cur = cur->kids[target];
      }
      else
      {
        done = true;
      }
    }
    if (j == s.size() && !done)
    {
      vector<int> ps;
      string s;
      tree_search(cur, ps, s, idx);
      for (auto k : ps)
      {
        ans.emplace_back(vector<int>{ idx, k });
      }
    }
  }

  void tree_search(TrieNode* root, vector<int>& ps, string& s, int idx)
  {
    if (root->eow >= 0 && is_palindrom(s, 0, s.size() - 1) && root->eow != idx)
    {
      ps.push_back(root->eow);
    }
    for (int i = 0; i < 26; i++)
    {
      if (root->kids[i])
      {
        s.push_back(i + 'a');
        tree_search(root->kids[i], ps, s, idx);
        s.pop_back();
      }
    }
  }

  bool is_palindrom(string& s, int i, int j)
  {
    while (i < j)
    {
      if (s[i++] != s[j--])
        return false;
    }
    return true;
  }
};

