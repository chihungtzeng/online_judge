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

vector<int> lps_of(const string& s)
{
  vector<int> lps(s.size());
  int k = 0;
  for (int i = 1; i < s.size(); i++)
  {
    if (s[i] == s[k])
    {
      k++;
      lps[i] = k;
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

vector<int> str_match(string& haystack, string& needle)
{
  auto lps = lps_of(needle);
  vector<int> res;
  for (int i = 0, j = 0; i < haystack.size(); i++)
  {
    while (j > 0 && needle[j] != haystack[i])
    {
      j = lps[j - 1];
    }

    if (haystack[i] == needle[j])
    {
      j++;
    }

    if (j == needle.size())
    {
      res.push_back(i - j + 1);
      j = lps[j - 1];
    }
  }
  return res;
}
