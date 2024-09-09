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

constexpr int nbase = 16;
class TreeAncestor {
 public:
  vector<vector<int>> parents_;
  TreeAncestor(int n, vector<int>& parent) {
    parents_ = vector<vector<int>>(n, vector<int>(nbase, -1));
    for (int u = 0; u < n; u++) {
      parents_[u][0] = parent[u];
    }

    for (int i = 1; i < nbase; i++) {
      for (int u = 0; u < n; u++) {
        int p = parents_[u][i - 1];
        if (p >= 0) {
          parents_[u][i] = parents_[p][i - 1];
        } else {
          parents_[u][i] = -1;
        }
      }
    }
  }

  int getKthAncestor(int u, int k) {
    while (k >= 1 && u >= 0) {
      int base = 0;
      while ((1 << base) < k) base++;
      if ((1 << base) > k) base--;
      u = parents_[u][base];
      k -= (1 << base);
    }
    return u;
  }
};

