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

using ipair = pair<int, int>;
class Solution
{
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k)
  {
    vector<int> dist(n + 1, INT_MAX);
    vector<vector<int>> nbrs(n + 1);
    vector<unordered_map<int, int>> weights(n + 1);
    for (auto& edge : times)
    {
      int u = edge[0], v = edge[1];
      nbrs[u].push_back(v);
      weights[u][v] = edge[2];
    }
    dist[k] = 0;
    priority_queue<ipair, vector<ipair>, greater<>> pq;
    pq.push({ 0, k });
    while (!pq.empty())
    {
      auto [d, cur] = pq.top();
      pq.pop();
      if (d > dist[cur])
        continue;
      for (auto nbr : nbrs[cur])
      {
        if (dist[nbr] > dist[cur] + weights[cur][nbr])
        {
          dist[nbr] = dist[cur] + weights[cur][nbr];
          pq.push({ dist[nbr], nbr });
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      if (dist[i] == INT_MAX)
        return -1;
      else
        ans = max(ans, dist[i]);
    }
    return ans;
  }
};
