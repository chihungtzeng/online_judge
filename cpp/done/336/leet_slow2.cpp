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
    unordered_map<string, int> rw2idx;
    bool has_empty = false;
    int es_idx = -1;
    for (int i = 0; i < words.size(); i++)
    {
      if (words[i].empty())
      {
        has_empty = true;
        es_idx = i;
      }
      else
      {
        string rw = words[i];
        reverse(rw.begin(), rw.end());

        rw2idx[rw] = i;
      }
    }

    vector<vector<int>> ans;
    ans.reserve(1000);

    if (has_empty)
    {
      for (int i = 0; i < words.size(); i++)
      {
        if (i == es_idx)
          continue;
        if (is_palindrom(words[i]))
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
        helper(words, rw2idx, ans, i);
      }
    }

    return ans;
  }

  void helper(vector<string>& words, unordered_map<string, int>& rw2idx, vector<vector<int>>& ans, int idx)
  {
    string left = words[idx];
    string right = "";
    bool done = false;
    while (!done)
    {
      //      LOG(INFO) << "left: " << left << ", right: " << right;
      auto it = rw2idx.find(left);
      if (it != rw2idx.end() && it->second != idx && is_palindrom(right))
      {
        ans.emplace_back(vector<int>{ idx, it->second });
      }
      auto it2 = rw2idx.find(right);
      if (it2 != rw2idx.end() && it2->second != idx && is_palindrom(left))
      {
        ans.emplace_back(vector<int>{ it2->second, idx });
      }
      if (left.size() <= 1)
      {
        done = true;
      }
      else
      {
        char last = left.back();
        left.pop_back();
        right = last + right;
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

