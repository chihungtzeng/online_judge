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

class DisjointSet {
 public:
  DisjointSet(const int n) : ranks_(n, 0), parents_(n), num_sets_(n) {
    for (int i = 0; i < n; i++) {
      parents_[i] = i;
    }
  }
  int find(int x) {
    if (x != parents_[x]) {
      parents_[x] = find(parents_[x]);
    }
    return parents_[x];
  }
  void join(int u, int v) {
    int uroot = find(u), vroot = find(v);
    if (uroot == vroot) return;
    if (ranks_[uroot] < ranks_[vroot]) {
      parents_[uroot] = vroot;
    } else if (ranks_[uroot] == ranks_[vroot]) {
      parents_[uroot] = vroot;
      ranks_[vroot]++;
    } else {
      parents_[vroot] = uroot;
    }
    num_sets_--;
  }
  int get_num_sets() const { return num_sets_; }

 private:
  vector<int> ranks_, parents_;
  int num_sets_;
};

class Solution {
 public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(
      int n, vector<vector<int>>& edges) {
    auto cmp = [](const auto& e1, const auto& e2) { return e1[2] < e2[2]; };
    for (int i = 0, nedges = edges.size(); i < nedges; i++) {
      edges[i].push_back(i);
    }
    sort(edges.begin(), edges.end(), cmp);
    int min_cost =
        build_mst(n, edges, vector<int>{-1, -1, -1}, vector<int>{-1, -1, -1});
    vector<int> critical, pseudo;
    for (int i = 0, nedges = edges.size(); i < nedges; i++) {
      int cost = build_mst(n, edges, edges[i], vector<int>{-1, -1, -1});
      if (cost > min_cost) {
        critical.push_back(edges[i][3]);
        continue;
      }
      cost = build_mst(n, edges, vector<int>{-1, -1, -1}, edges[i]);
      if (cost == min_cost) {
        pseudo.push_back(edges[i][3]);
      }
    }
    return {critical, pseudo};
  }
  int build_mst(const int n, vector<vector<int>>& edges, vector<int> skip_edge,
                vector<int> force_edge) {
    auto ds = DisjointSet(n);
    int cost = 0;
    if (force_edge[0] >= 0) {
      ds.join(force_edge[0], force_edge[1]);
      cost += force_edge[2];
    }
    for (auto& edge : edges) {
      if (edge[0] == skip_edge[0] && edge[1] == skip_edge[1]) continue;
      int u = edge[0], v = edge[1], w = edge[2];
      if (ds.find(u) == ds.find(v)) continue;
      ds.join(u, v);
      cost += w;
      if (ds.get_num_sets() == 1) break;
    }
    if (ds.get_num_sets() == 1)
      return cost;
    else
      return INT_MAX;
  }
};
