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
  vector<int> findOrder(int ncourse, vector<vector<int>>& prerequisites)
  {
    vector<int> out_degrees(ncourse, 0);
    vector<vector<int>> successors(ncourse);
    for (auto& edge : prerequisites)
    {
      int prev = edge[1], succ = edge[0];
      successors[prev].push_back(succ);
      out_degrees[succ]++;
    }
    deque<int> q;
    vector<int> ans;
    ans.reserve(ncourse);
    for (int i = 0; i < ncourse; i++)
    {
      if (out_degrees[i] == 0)
      {
        q.push_back(i);
      }
    }
    while (!q.empty())
    {
      int cur = q.front();
      ans.push_back(cur);
      q.pop_front();
      for (auto succ : successors[cur])
      {
        out_degrees[succ]--;
        if (out_degrees[succ] == 0)
        {
          q.push_back(succ);
        }
      }
    }
    if (ans.size() == ncourse)
    {
      return ans;
    }
    else
    {
      return {};
    }
  }
};
