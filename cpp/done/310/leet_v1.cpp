#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n <= 0) {
      return vector<int>{};
    }
    vector<int> degrees(n), heights(n, n);
    vector<vector<int>> nbrs(n);
    for (auto& edge : edges) {
      degrees[edge[0]]++;
      degrees[edge[1]]++;
      nbrs[edge[0]].push_back(edge[1]);
      nbrs[edge[1]].push_back(edge[0]);
    }
    deque<int> queue;
    for (int i = 0; i < n; i++) {
      if (degrees[i] == 1) {
        heights[i] = 0;
        queue.push_back(i);
      }
    }
    while (!queue.empty()) {
      auto i = queue.front();
      queue.pop_front();
      for (auto nbr : nbrs[i]) {
        degrees[nbr]--;
        if (degrees[nbr] == 1) {
          queue.push_back(nbr);
          heights[nbr] = 1 + heights[i];
        }
      }
    }
    int max_height = *max_element(heights.begin(), heights.end());
    // LOG(INFO) << heights;
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      if (heights[i] == max_height) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
