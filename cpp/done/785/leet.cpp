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
  bool isBipartite(vector<vector<int>>& graph)
  {
    vector<int8_t> colors(graph.size(), -1);
    for (int i = graph.size() - 1; i >= 0; i--)
    {
      if (colors[i] == -1)
      {
        colors[i] = 0;
        if (!dfs(graph, colors, i))
          return false;
      }
    }
    return true;
  }
  bool dfs(vector<vector<int>>& graph, vector<int8_t>& colors, const int cur)
  {
    int8_t nbr_color = 1 - colors[cur];
    for (auto nbr : graph[cur])
    {
      if (colors[nbr] == -1)
      {
        colors[nbr] = nbr_color;
        if (!dfs(graph, colors, nbr))
          return false;
      }
      else if (colors[nbr] != nbr_color)
      {
        return false;
      }
    }
    return true;
  }
};
