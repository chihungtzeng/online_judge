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
  int numSpecialEquivGroups(vector<string>& words)
  {
    unordered_set<string> gs;
    for (const auto& s : words)
    {
      gs.insert(convert(s));
    }
    return gs.size();
  }

  string convert(const string& s)
  {
    const int n = s.size();
    vector<char> even, odd;
    even.reserve(n >> 1);
    odd.reserve(n >> 1);
    int i = 0;
    while (i < n)
    {
      even.push_back(s[i++]);
      if (i < n)
      {
        odd.push_back(s[i++]);
      }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    string res;
    for (int i = 0; i < odd.size(); i++)
    {
      res.push_back(even[i]);
      res.push_back(odd[i]);
    }
    if (n & 1)
    {
      res.push_back(even.back());
    }
    return res;
  }
};
