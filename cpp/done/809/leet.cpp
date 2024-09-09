#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using cipair = pair<char, int>;

class Solution
{
public:
  int expressiveWords(string s, vector<string>& words)
  {
    auto h_cipairs = cmpr(s);
    int ans = 0;
    for (auto& w : words)
    {
      ans += can_express(w, h_cipairs);
    }
    return ans;
  }
  int can_express(string& needle, vector<cipair>& h_cipairs)
  {
    auto n_cipairs = cmpr(needle);
    if (n_cipairs.size() != h_cipairs.size())
      return 0;

    for (int i = n_cipairs.size() - 1; i >= 0; i--)
    {
      if (n_cipairs[i].first != h_cipairs[i].first)
        return 0;

      int hs = h_cipairs[i].second;
      int ns = n_cipairs[i].second;
      if (hs <= 2) {
        if (ns != hs) return 0;
      }
      else {
        if (hs < ns) return 0;
      }
    }
    return 1;
  }
  vector<cipair> cmpr(const string& s)
  {
    int i = 0;
    char ch = 0;
    int cnt = 0;
    vector<cipair> res;
    while (i < s.size())
    {
      ch = s[i];
      cnt = 1;
      while (i < s.size() && s[i + 1] == ch)
      {
        i++;
        cnt++;
      }
      res.push_back({ ch, cnt });
      i++;
    }
    return res;
  }
};
