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
#define DEBUG 0

struct DisjointSet {
  int n_;
  vector<int> parents_, ranks_;
  DisjointSet(int n) : n_(n), parents_(n), ranks_(n) {
    for (int i = 0; i < n; i++) {
      parents_[i] = i;
    }
  }
  int find(int u) {
    if (u != parents_[u]) {
      parents_[u] = find(parents_[u]);
    }
    return parents_[u];
  }
  void join(int u, int v) {
    int ur = find(u), vr = find(v);
    if (ur == vr) return;
    if (ranks_[ur] < ranks_[vr]) {
      parents_[ur] = vr;
    } else if (ranks_[ur] == ranks_[vr]) {
      parents_[ur] = vr;
      ranks_[vr]++;
    } else {
      parents_[vr] = ur;
    }
  }
  void dump() {
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < n_; i++) {
      groups[find(i)].push_back(i);
    }
    for (auto& [gid, ids] : groups) {
      if (ids.size() <= 1) continue;
      cout << "group " << gid << " : ";
      for (auto& id : ids) {
        cout << id << " ";
      }
      cout << endl;
    }
  }
};

using ipair = pair<int, int>;
class Solution {
 public:
  int rows, cols;
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    rows = matrix.size();
    cols = matrix[0].size();
    unordered_map<int, vector<ipair>> val2pos;
    set<int> vals;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        val2pos[matrix[r][c]].emplace_back(r, c);
        vals.insert(matrix[r][c]);
      }
    }
    vector<vector<int>> ans(rows, vector<int>(cols));
    vector<int> ranks(rows + cols);

    for (auto val : vals) {
#if DEBUG
      cout << "position of val " << val << " : ";
      for (auto& [r, c] : val2pos[val]) {
        cout << "(" << r << ", " << c << "), ";
      }
      cout << endl;
      LOG(INFO) << "ranks before update: " << ranks;
#endif
      DisjointSet ds(rows + cols);
      for (auto& [r, c] : val2pos[val]) {
        ds.join(r, rows + c);
      }
      auto ranks2 = ranks;
      for (auto& [r, c] : val2pos[val]) {
        int root = ds.find(r);
        ranks2[root] = max(ranks2[root], ranks2[r]);
        ranks2[root] = max(ranks2[root], ranks2[rows + c]);
      }
      for (auto& [r, c] : val2pos[val]) {
        int root = ds.find(r);
        int rank = ranks2[root] + 1;
        ranks[r] = rank;
        ranks[rows + c] = rank;
        ans[r][c] = rank;
      }
#if DEBUG
      LOG(INFO) << "group of val " << val;
      ds.dump();
#endif
    }
    return ans;
  }
};
