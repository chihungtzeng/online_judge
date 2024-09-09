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
    vector<int> valid_pos, invalid_pos;
    for (int i = 25; i >= 0; i--)
    {
      if (tchars[i])
        valid_pos.push_back(i);
      else
        invalid_pos.push_back(i);
    }

    vector<string> schars(stickers.size());
    for (int i = stickers.size() - 1; i >= 0; i--)
    {
      schars[i] = to_char_cnt(stickers[i]);
    }
    if (!is_possible(schars, tchars))
      return -1;

    for (int i = stickers.size() - 1; i >= 0; i--)
    {
      if (!target_needs(schars[i], tchars))
      {
        schars.erase(schars.begin() + i);
      }
    }

    for (auto i : invalid_pos)
    {
      tchars.erase(tchars.begin() + i);
    }

    for (auto& scnt : schars)
    {
      for (auto i : invalid_pos)
      {
        scnt.erase(scnt.begin() + i);
      }
    }

    map<string, int> cache;
    return helper(schars, tchars, cache);
  }
  int helper(vector<string>& schars, string& tchars, map<string, int>& cache)
  {
    // LOG(INFO) << tchars;
    if (no_more_char_needed(tchars))
      return 0;

    auto it = cache.find(tchars);
    if (it != cache.end())
    {
      return it->second;
    }
    int ans = INT_MAX;
    for (int i = schars.size() - 1; i >= 0; i--)
    {
      if (target_needs(schars[i], tchars))
      {
        auto after_taking = take_stick(schars[i], tchars);
        ans = min(ans, helper(schars, after_taking, cache) + 1);
      }
    }
    cache[tchars] = ans;

    return ans;
  }

  bool target_needs(string& scnt, string& tchars)
  {
    for (int i = scnt.size() - 1; i >= 0; i--)
    {
      if (tchars[i] > 0 && scnt[i] > 0)
        return true;
    }
    return false;
  }

  string take_stick(string& scnt, string& tchars)
  {
    string after(scnt.size(), 0);
    for (int i = scnt.size() - 1; i >= 0; i--)
    {
      after[i] = max(0, tchars[i] - scnt[i]);
    }
    return after;
  }

  bool no_more_char_needed(string& tchars)
  {
    for (int i = tchars.size() - 1; i >= 0; i--)
    {
      if (tchars[i] > 0)
        return false;
    }
    return true;
  }

  bool is_possible(vector<string>& schars, string& tchars)
  {
    vector<int> can(tchars.size(), 0);
    for (auto& scnt : schars)
    {
      for (int i = tchars.size() - 1; i >= 0; i--)
      {
        if (scnt[i])
          can[i] = 1;
      }
    }
    for (int i = tchars.size() - 1; i >= 0; i--)
    {
      if (tchars[i] && !can[i])
        return false;
    }
    return true;
  }

  string to_char_cnt(string& s)
  {
    string cnt(26, 0);
    for (auto ch : s)
    {
      cnt[ch - 'a']++;
    }
    return cnt;
  }
};
