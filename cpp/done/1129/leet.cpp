#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges)
  {
    constexpr int red = 0, blue = 1;
    vector<vector<vector<int>>> nbrs(2, vector<vector<int>>(n));
    for (auto& e : red_edges)
    {
      nbrs[red][e[0]].push_back(e[1]);
    }

    for (auto& e : blue_edges)
    {
      nbrs[blue][e[0]].push_back(e[1]);
    }
#if 0    
    for(int i=0; i<n; i++){
      LOG(INFO) << "red nbrs of " << i << ": " << nbrs[red][i];
    }
#endif

    vector<vector<int>> dists(2, vector<int>(n, INT_MAX));
    dists[red][0] = 0;
    dists[blue][0] = 0;
    deque<int> q;
    q.push_back(0);
    q.push_back(1);

    while (!q.empty())
    {
      auto blob = q.front();
      int cur = blob >> 1;
      int color = blob & 1;
      q.pop_front();
      int next_color = 1 - color;
      for (auto nbr : nbrs[next_color][cur])
      {
        if (dists[next_color][nbr] > dists[color][cur] + 1)
        {
          dists[next_color][nbr] = dists[color][cur] + 1;
          q.push_back((nbr << 1) + next_color);
        }
      }
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
      ans[i] = min(dists[red][i], dists[blue][i]);
      if (ans[i] == INT_MAX)
      {
        ans[i] = -1;
      }
    }
    return ans;
  }
};
