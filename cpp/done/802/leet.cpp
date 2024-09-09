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

class Solution
{
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph)
  {
    int n = graph.size();
    vector<int> out_degrees(n);
    vector<vector<int>> pred(n);
    deque<int> q;
    for (int i = n - 1; i >= 0; i--)
    {
      out_degrees[i] = graph[i].size();
      if (out_degrees[i] == 0)
      {
        q.push_back(i);
      }
      for (auto succ : graph[i])
      {
        pred[succ].push_back(i);
      }
    }
    vector<int> ans;
    while (!q.empty())
    {
      int cur = q.front();
      ans.push_back(cur);
      q.pop_front();
      for (auto nbr : pred[cur])
      {
        out_degrees[nbr]--;
        if (out_degrees[nbr] == 0)
        {
          q.push_back(nbr);
        }
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
