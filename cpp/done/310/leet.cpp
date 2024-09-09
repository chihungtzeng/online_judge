#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
  {
    if (n == 1)
      return vector<int>{ 0 };
    vector<vector<int>> nbrs(n);
    for (auto& edge : edges)
    {
      int u = edge[0], v = edge[1];
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }
    vector<int> cur, prev;
    vector<int> degrees(n);
    vector<bool> visited(n, false);
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
      degrees[i] = nbrs[i].size();
      if (degrees[i] == 1)
      {
        q.push_back(i);
        visited[i] = true;
      }
    }
    while (!q.empty())
    {
      // LOG(INFO) << degrees;
      int qs = q.size();
      for (int i = 0; i < qs; i++)
      {
        int u = q[i];
        cur.push_back(u);
        for (auto nbr : nbrs[u])
        {
          degrees[nbr]--;
          if (degrees[nbr] == 1 && !visited[nbr])
          {
            q.push_back(nbr);
            visited[nbr] = true;
          }
        }
      }
      for (int i = 0; i < qs; i++)
      {
        q.pop_front();
      }
      // LOG(INFO) << "cur: " << cur;
      swap(prev, cur);
      cur.clear();
    }
    return prev;
  }
};
