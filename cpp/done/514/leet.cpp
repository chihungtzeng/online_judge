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
  int findRotateSteps(string ring, string key)
  {
    const int n = ring.size(), m = key.size();
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        dist[i][j] = min(j - i, n - j + i);
        dist[j][i] = dist[i][j];
      }
    }
    vector<vector<int>> char_pos(256);
    for (int i = 0; i < n; i++)
    {
      char_pos[ring[i]].push_back(i);
    }
    vector<int> src(n, n), dest(n), src_pos;
    src[0] = 0;
    src_pos.push_back(0);
    for (int i = 0; i < m; i++)
    {
      for (auto to : char_pos[key[i]])
      {
        int d = INT_MAX;
        for (auto from : src_pos)
        {
          d = min(d, dist[from][to] + src[from]);
        }
        dest[to] = d;
      }
      src_pos.clear();
      for (auto to : char_pos[key[i]])
      {
        src_pos.push_back(to);
      }
      swap(src, dest);
    }
    int res = INT_MAX;
    for (auto idx : char_pos[key.back()])
    {
      res = min(src[idx], res);
    }
    res += key.size();

    return res;
  }
};

