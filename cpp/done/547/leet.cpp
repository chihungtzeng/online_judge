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

class DisjointSet
{
public:
  vector<int> parents, ranks;
  DisjointSet(int n) : parents(n), ranks(n, 0)
  {
    for (int i = 0; i < n; i++)
    {
      parents[i] = i;
    }
  }
  int find(int u)
  {
    if (parents[u] != u)
    {
      parents[u] = find(parents[u]);
    }
    return parents[u];
  }
  void join(int u, int v)
  {
    int ur = find(u), vr = find(v);
    if (ur == vr)
      return;
    if (ranks[ur] < ranks[vr])
    {
      parents[ur] = vr;
    }
    else if (ranks[ur] == ranks[vr])
    {
      parents[ur] = vr;
      ranks[vr]++;
    }
    else
    {
      parents[vr] = ur;
    }
  }
};

class Solution
{
public:
  int findCircleNum(vector<vector<int>>& grid)
  {
    int n = grid.size();
    DisjointSet ds(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (grid[i][j])
        {
          ds.join(i, j);
        }
      }
    }
    int ngroup = 0;
    for (int i = 0; i < n; i++)
    {
      if (i == ds.find(i))
      {
        ngroup++;
      }
    }
    return ngroup;
  }
};
