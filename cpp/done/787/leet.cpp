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
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
  {
    using ipair = pair<int, int>;
    vector<vector<ipair>> nbrs(n);
    for (auto& flight : flights)
    {
      int from = flight[0], to = flight[1], price = flight[2];
      nbrs[from].push_back({ to, price });
    }
    vector<vector<int>> dists(k + 2, vector<int>(n, INT_MAX));
    priority_queue<ipair, vector<ipair>, greater<>> pq;
    pq.push({ 0, src });
    dists[0][src] = 0;
    while (!pq.empty())
    {
      auto [nstop, cur] = pq.top();
      pq.pop();
      if (nstop >= k + 1)
        continue;
      for (auto& [nbr, price] : nbrs[cur])
      {
        //        LOG(INFO) << "nstop, cur: " << ipair{nstop, cur} << " nbr: " << nbr;
        if (dists[nstop + 1][nbr] > dists[nstop][cur] + price)
        {
          dists[nstop + 1][nbr] = dists[nstop][cur] + price;
          pq.push({ nstop + 1, nbr });
        }
      }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= k + 1; i++)
    {
      ans = min(ans, dists[i][dst]);
    }
    if (ans == INT_MAX)
      return -1;
    else
      return ans;
  }
};
