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

using ipair = pair<int, int>;
constexpr int base = 1e9 + 7;

struct Node {
  unordered_map<int, int> weights;
  int dist, nways;
  bool seen;
  Node() : dist(INT_MAX), nways(0), seen(false) {}
};

class Solution {
 public:
  int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    vector<Node> nodes(n + 1);
    for (auto& e : edges) {
      auto u = e[0], v = e[1], w = e[2];
      nodes[u].weights[v] = w;
      nodes[v].weights[u] = w;
    }
    nodes[n].dist = 0;
    priority_queue<ipair, vector<ipair>, greater<>> q;
    q.push({0, n});
    while (!q.empty()) {
      auto [d, cur] = q.top();
      q.pop();
      for (auto [nbr, w] : nodes[cur].weights) {
        if (nodes[nbr].dist > d + w) {
          nodes[nbr].dist = d + w;
          q.push({nodes[nbr].dist, nbr});
        }
      }
    }
    priority_queue<ipair> q2;
    q2.push({nodes[1].dist, 1});
    nodes[1].nways = 1;
    nodes[1].seen = true;
    while (!q2.empty()) {
      auto [d, cur] = q2.top();
      q2.pop();
      for (auto [nbr, w] : nodes[cur].weights) {
        if (nodes[nbr].dist < d) {
          nodes[nbr].nways += nodes[cur].nways;
          nodes[nbr].nways %= base;
          if (!nodes[nbr].seen) {
            nodes[nbr].seen = true;
            q2.push({nodes[nbr].dist, nbr});
          }
        }
      }
    }
    return nodes[n].nways;
  }
};
