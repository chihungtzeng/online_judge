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
class Solution {
 public:
  int maxJumps(vector<int>& arr, int d) {
    const int n = arr.size();
    vector<vector<int>> edges(n);
    deque<ipair> q;
    for (int i = 0; i < n; i++) {
      while (!q.empty() && q.back().second < arr[i]) {
        edges[i].push_back(q.back().first);
        q.pop_back();
      }
      while (!q.empty() && q.front().first <= i - d) {
        q.pop_front();
      }
      q.push_back({i, arr[i]});
    }
    q.clear();

    for (int i = n - 1; i >= 0; i--) {
      while (!q.empty() && q.back().second < arr[i]) {
        edges[i].push_back(q.back().first);
        q.pop_back();
      }
      while (!q.empty() && q.front().first >= i + d) {
        q.pop_front();
      }
      q.push_back({i, arr[i]});
    }

    vector<int> indegrees(n);
    for (int i = 0; i < n; i++) {
      for (auto nbr : edges[i]) {
        indegrees[nbr]++;
      }
    }
    vector<int> dist(n, 0);
    deque<int> q2;
    for (int i = 0; i < n; i++) {
      if (indegrees[i] == 0) {
        dist[i] = 1;
        q2.push_back(i);
      }
    }
    while (!q2.empty()) {
      int cur = q2.front();
      q2.pop_front();
      for (auto nbr : edges[cur]) {
        indegrees[nbr]--;
        if (indegrees[nbr] == 0) {
          dist[nbr] = dist[cur] + 1;
          q2.push_back(nbr);
        }
      }
    }

    return *max_element(dist.begin(), dist.end());
  }
};
