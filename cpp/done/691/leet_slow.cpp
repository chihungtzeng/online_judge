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
  int minStickers(vector<string>& stickers, string target)
  {
    auto tchars = to_char_cnt(target);
    vector<int> valid_pos;
    for (int i = 0; i < 26; i++)
    {
      if (tchars[i])
        valid_pos.push_back(i);
    }
    vector<vector<int>> schars(stickers.size());
    for (int i = stickers.size() - 1; i >= 0; i--)
    {
      schars[i] = to_char_cnt(stickers[i]);
    }
    if (!is_possible(schars, tchars))
      return -1;

    map<vector<int>, int> cache;
    return helper(schars, tchars, valid_pos, cache);
  }
  int helper(const vector<vector<int>>& schars, const vector<int>& tchars, const vector<int>& valid_pos,
             map<vector<int>, int>& cache)
  {
    // LOG(INFO) << tchars;
    if (no_more_char_needed(tchars, valid_pos))
      return 0;

    auto it = cache.find(tchars);
    if (it != cache.end())
    {
      return it->second;
    }
    int ans = INT_MAX;
    for (int i = schars.size() - 1; i >= 0; i--)
    {
      if (target_needs(schars[i], tchars, valid_pos))
      {
        auto after_taking = take_stick(schars[i], tchars, valid_pos);
        ans = min(ans, helper(schars, after_taking, valid_pos, cache) + 1);
      }
    }
    cache[tchars] = ans;

    return ans;
  }

  bool target_needs(const vector<int>& scnt, const vector<int>& tchars, const vector<int>& valid_pos)
  {
    for (auto i : valid_pos)
    {
      if (tchars[i] > 0 && scnt[i] > 0)
        return true;
    }
    return false;
  }

  vector<int> take_stick(const vector<int>& scnt, const vector<int>& tchars, const vector<int>& valid_pos)
  {
    vector<int> after(26);
    for (auto i : valid_pos)
    {
      after[i] = max(0, tchars[i] - scnt[i]);
    }
    return after;
  }

  bool no_more_char_needed(const vector<int>& tchars, const vector<int>& valid_pos)
  {
    for (auto i : valid_pos)
    {
      if (tchars[i] > 0)
        return false;
    }
    return true;
  }

  bool is_possible(vector<vector<int>>& schars, vector<int>& tchars)
  {
    vector<int> can(26, 0);
    for (auto& scnt : schars)
    {
      for (int i = 0; i < 26; i++)
      {
        if (scnt[i])
          can[i] = 1;
      }
    }
    for (int i = 0; i < 26; i++)
    {
      if (tchars[i] && !can[i])
        return false;
    }
    return true;
  }

  vector<int> to_char_cnt(const string& s)
  {
    vector<int> cnt(26);
    for (auto ch : s)
    {
      cnt[ch - 'a']++;
    }
    return cnt;
  }
};
