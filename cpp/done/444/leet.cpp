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
  bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    const int n = org.size();
    if (n == 1 && seqs.empty()) return false;

    vector<int> indegrees(n + 1);
    unordered_map<int, unordered_set<int>> graph;

    for (auto& seq : seqs) {
      for (int i = seq.size() - 1; i >= 0; i--) {
        int from = seq[i];
        if (from < 1 || from > n) return false;
        if (i <= 0) continue;
        int to = seq[i - 1];
        if (to > 0 && to <= n && graph[from].find(to) == graph[from].end()) {
          indegrees[to]++;
        }
        graph[from].insert(to);
      }
    }
#if 0
    for(int i=0; i<indegrees.size(); i++){
      LOG(INFO) << "node " << i << " indegree: " << indegrees[i] << " nbrs: ";
      for(auto nbr: graph[i]){
        std::cout << nbr << " ";
      }
      std::cout << endl;
    }
#endif
    int count = 0;
    for (auto deg : indegrees) {
      if (deg > 0) count++;
    }
    if (count != n - 1) return false;
    for (int i = n - 1; i >= 0; i--) {
      int cur = org[i];
      if (indegrees[cur] > 0) {
        // LOG(INFO) << "cur " << cur << " indegree > 0";
        return false;
      }
      for (auto nbr : graph[cur]) {
        indegrees[nbr] -= 1;
        if (indegrees[nbr] == 0 && i > 0 && nbr != org[i - 1]) {
          // LOG(INFO) << "nbr " << nbr << " indegree down to 0";
          return false;
        }
      }
    }
    return true;
  }
};
