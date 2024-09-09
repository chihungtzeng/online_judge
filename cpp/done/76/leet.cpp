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
  string minWindow(string s, string t)
  {
    if (s.size() < t.size())
      return "";
    vector<int> need(128, 0);
    for (auto ch : t)
    {
      need[ch]++;
    }
    const int tsz = t.size();
    for (int i = 0; i < tsz; i++)
    {
      need[s[i]]--;
    }
    if (satisfy(need))
    {
      return s.substr(0, tsz);
    }
    int j = 0, from = 0, to = s.size();
    for (int i = t.size(); i < s.size(); i++)
    {
      need[s[i]]--;
      while (satisfy(need) && j <= i)
      {
        // LOG(INFO) << "bingo: " << j << " -> " << i << " : " << s.substr(j, i-j+1) << "; from, to: " << from << "," <<
        // to;
        if (i - j < to - from)
        {
          from = j;
          to = i;
        }
        need[s[j++]]++;
      }
    }
    if (to - from + 1 > s.size())
      return "";
    else
      return s.substr(from, to - from + 1);
  }
  inline bool satisfy(const vector<int>& need)
  {
    for (int i = 'a'; i <= 'z'; i++)
    {
      if (need[i] > 0)
        return false;
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
      if (need[i] > 0)
        return false;
    }
    return true;
  }
};
