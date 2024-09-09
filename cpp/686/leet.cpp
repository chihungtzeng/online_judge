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
  int repeatedStringMatch(string needle, string haystack)
  {
    auto mps = match_points(needle, haystack);
    if (!mps.empty()) return 1;

    mps = match_points(haystack, needle);
    for (auto start : mps)
    {
      if (start >= needle.size())
        break;

      string reorg = haystack.substr(start) + haystack.substr(0, start);
      if (is_repeated(reorg, needle))
      {
        int offset = (start == 0) ? 0 : 1;
        return reorg.size() / needle.size() + offset;
      }
    }
    return -1;
  }

  bool is_repeated(string& haystack, string& needle)
  {
    if (haystack.size() % needle.size() != 0)
      return false;
    for (int i = 0; i < haystack.size(); i += needle.size())
    {
      if (needle != haystack.substr(i, needle.size()))
      {
        return false;
      }
    }
    return true;
  }

  vector<int> match_points(string& haystack, string& needle)
  {
    auto lps = lps_of(needle);
    vector<int> mps;

    for (int i = 0, k = 0; i < haystack.size(); i++)
    {
      if (haystack[i] == needle[k])
      {
        k++;
      }
      else
      {
        while (k > 0 && needle[k] != haystack[i])
        {
          k = lps[k - 1];
        }
        if (haystack[i] == needle[k]) k++; 
      }
      if (k == needle.size())
      {
        mps.push_back(i - k + 1);
        k = lps[k - 1];
      }
    }
    return mps;
  }

  vector<int> lps_of(string& s)
  {
    vector<int> lps(s.size());
    for (int i = 1, k = 0; i < s.size(); i++)
    {
      if (s[i] == s[k])
      {
        lps[i] = ++k;
      }
      else
      {
        while (k > 0 && s[lps[k - 1]] != s[i])
        {
          k = lps[k - 1];
        }
        lps[i] = k;
      }
    }
    return lps;
  }
};
