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

struct Record {
  int dist_, src_, nstop_;
  Record(int dist, int src, int nstop)
      : dist_(dist), src_(src), nstop_(nstop) {}
  bool operator<(const Record& other) const { return dist_ > other.dist_; }
};

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<vector<int>> nbrs(n);
    unordered_map<int, unordered_map<int, int>> costs;
    for (auto& f : flights) {
      nbrs[f[0]].push_back(f[1]);
      costs[f[0]][f[1]] = f[2];
    }
    for (int i = 0; i < n; i++) {
      sort(nbrs[i].begin(), nbrs[i].end());
    }
    priority_queue<Record> pq;
    pq.push({0, src, 0});
    while (!pq.empty()) {
      auto record = pq.top();
      pq.pop();
      int from = record.src_;
      if (from == dst) {
        return record.dist_;
      }
      if (record.nstop_ <= k) {
        for (auto nbr : nbrs[from]) {
          pq.push({record.dist_ + costs[from][nbr], nbr, record.nstop_ + 1});
        }
      }
    }
    return -1;
  }
  bool connected(vector<vector<int>>& nbrs, int u, int v) {
    auto it = lower_bound(nbrs[u].begin(), nbrs[u].end(), v);
    return (it != nbrs[u].end() && *it == v);
  }
};
