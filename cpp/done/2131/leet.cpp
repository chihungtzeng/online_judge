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
  int longestPalindrome(vector<string>& words)
  {
    unordered_map<string, int> cnt;
    for (auto& w : words)
    {
      cnt[w] += 1;
    }
    int ans = 0, mid = 0;

    for (auto& [s, freq] : cnt)
    {
      if (s[0] == s[1])
      {
        if (freq % 2 == 0)
        {
          ans += freq * 2;
        }
        else
        {
          ans += (freq - 1) * 2;
          mid = 2;
        }
      }
      else
      {
        string rev;
        rev.push_back(s[1]);
        rev.push_back(s[0]);
        auto it = cnt.find(rev);
        if (it != cnt.end())
        {
          ans += min(freq, it->second) * 2;
        }
      }
    }
    ans += mid;
    return ans;
  }
};
