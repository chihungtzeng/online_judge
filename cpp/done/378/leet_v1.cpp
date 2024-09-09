#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using pos_t = std::pair<int, int>;
using val_pos_t = std::pair<int, pos_t>;
struct cmp {
  bool operator()(const val_pos_t& a, const val_pos_t& b) const {
    return a.first > b.first;
  }
};

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto n = matrix.size();
    std::priority_queue<val_pos_t, vector<val_pos_t>, cmp> pq;
    pq.push({matrix[0][0], {0, 0}});

    while (--k) {
      auto [r, c] = pq.top().second;
      pq.pop();
      if (r < n - 1) {
        pq.push({matrix[r + 1][c], {r + 1, c}});
        matrix[r + 1][c] = INT_MAX;
      }
      if (c < n - 1) {
        pq.push({matrix[r][c + 1], {r, c + 1}});
        matrix[r][c + 1] = INT_MAX;
      }
    }
    return pq.top().first;
  }
};
