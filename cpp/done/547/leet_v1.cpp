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
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    if (n == 0) return 0;
    vector<int> groups(n), ranks(n);
    for (int i = 0; i < n; i++) {
      groups[i] = i;
      ranks[i] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (M[i][j]) {
          union_(groups, ranks, i, j);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      find(groups, i);
    }
    // LOG(INFO) << groups;
    unordered_set<int> g;
    for (auto p : groups) {
      g.insert(p);
    }
    return g.size();
  }
  int find(vector<int>& parents, int x) {
    if (parents[x] != x) {
      parents[x] = find(parents, parents[x]);
    }
    return parents[x];
  }
  void union_(vector<int>& parents, vector<int>& ranks, int x, int y) {
    auto xroot = find(parents, x);
    auto yroot = find(parents, y);
    if (xroot == yroot) return;
    if (ranks[xroot] < ranks[yroot]) {
      parents[xroot] = yroot;
    } else if (ranks[xroot] > ranks[yroot]) {
      parents[yroot] = xroot;
    } else {
      parents[xroot] = yroot;
      ranks[xroot] += 1;
    }
  }
};
