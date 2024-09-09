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

using ispair = pair<int, string>;
class Solution
{
public:
  vector<string> topKFrequent(vector<string>& words, int k)
  {
    unordered_map<string, int> scnt;
    for (auto& w : words)
    {
      scnt[w]++;
    }
    auto cmp = [](const auto& a, const auto& b) {
      if (a.first != b.first)
        return a.first > b.first;
      else
        return a.second < b.second;
    };
    priority_queue<ispair, vector<ispair>, decltype(cmp)> pq(cmp);
    for (auto& [w, cnt] : scnt)
    {
      pq.push({ cnt, w });
      if (pq.size() > k)
        pq.pop();
    }
    vector<string> res;
    while (!pq.empty())
    {
      res.push_back(pq.top().second);
      pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
