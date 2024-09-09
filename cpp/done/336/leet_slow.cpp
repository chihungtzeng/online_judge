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

class Solution
{
public:
  vector<vector<int>> palindromePairs(vector<string>& words)
  {
    unordered_map<string, int> w2idx;
    for (int i = 0; i < words.size(); i++)
    {
      w2idx[words[i]] = i;
    }

    set<int> res;
    for (int i = 0; i < words.size(); i++)
    {
      helper(words, w2idx, res, i);
    }
    vector<vector<int>> ans;
    ans.reserve(res.size());
    for (auto& val : res)
    {
      ans.emplace_back(vector<int>{ val >> 16, val & 0xffff });
    }

    return ans;
  }

  void helper(vector<string>& words, unordered_map<string, int>& w2idx, set<int>& res, int idx)
  {
    string_view w = words[idx];
    for (int i = w.size(); i >= 0; i--)
    {
      string_view suffix = w.substr(i, w.size() - i);
      if (is_palindrom(suffix))
      {
        string expect{ w.begin(), w.begin() + i };
        reverse(expect.begin(), expect.end());
        auto it = w2idx.find(expect);
        if (it != w2idx.end() && it->second != idx)
        {
          int encode = (idx << 16) + it->second;
          res.insert(encode);
        }
      }
      string_view prefix = w.substr(0, i);
      if (is_palindrom(prefix))
      {
        string expect{ w.begin() + i, w.end() };
        reverse(expect.begin(), expect.end());
        auto it = w2idx.find(expect);
        if (it != w2idx.end() && it->second != idx)
        {
          int encode = (it->second << 16) + idx;
          res.insert(encode);
        }
      }
    }
  }

  bool is_palindrom(string_view s)
  {
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (s[i++] != s[j--])
        return false;
    }
    return true;
  }
};

