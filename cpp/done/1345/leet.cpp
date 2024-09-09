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

class Solution {
 public:
  int minJumps(vector<int>& arr) {
    const int n = arr.size();
    unordered_map<int, vector<int>> nbrs;
    for (int i = 0; i < n; i++) {
      nbrs[arr[i]].push_back(i);
    }
    vector<int> dist(n, INT_MAX);
    deque<int> q;
    dist[n - 1] = 0;
    q.push_back(n - 1);
    while (!q.empty()) {
      int cur = q.front();
      q.pop_front();
      int next_dist = dist[cur] + 1;
      for (auto nbr : nbrs[arr[cur]]) {
        if (dist[nbr] > next_dist) {
          dist[nbr] = next_dist;
          q.push_back(nbr);
        }
        nbrs[arr[cur]].clear();
      }
      vector<int> temp = {cur + 1, cur - 1};
      for (auto nbr : temp) {
        if (nbr >= 0 && nbr < n && dist[nbr] > next_dist) {
          dist[nbr] = next_dist;
          q.push_back(nbr);
        }
      }
    }
    return dist[0];
  }
};
