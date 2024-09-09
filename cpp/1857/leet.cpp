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

struct Node {
  vector<int> nbrs;
  int indegree;
  char color;
};

class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    vector<Node> nodes(colors.size());
    for (int i = 0; i < colors.size(); i++) {
      nodes[i].color = colors[i];
    }
    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      nodes[u].nbrs.push_back(v);
      nodes[v].indegree++;
    }
#if  1   
    for(int i=0; i<colors.size(); i++){
      LOG(INFO) << "i: " << i << " nbrs: " << nodes[i].nbrs;
    }
#endif
    int ans = -1;
    for (int i = 0; i < colors.size(); i++) {
      if (nodes[i].indegree == 0) {
      LOG(INFO) << "dig i: " << i << " nbrs: " << nodes[i].nbrs;
        vector<bool> seen(colors.size(), false);
        vector<int> cnt(26, 0);
        int can = dfs(nodes, i, cnt, seen);
        if (can < 0) {
          return -1;
        }
        ans = max(ans, can);
      }
    }
    return ans;
  }
  int dfs(vector<Node>& nodes, int i, vector<int>& cnt, vector<bool>& seen) {
    if (seen[i]) {
      return -1;
    }

    auto color = nodes[i].color;
    cnt[color - 'a']++;

    seen[i] = true;
    int can = 0;
    if (nodes[i].nbrs.empty()) {
      for (auto v : cnt) {
        can = max(can, v);
      }
      // LOG(INFO) << "i: " << i << ", cnt: " << cnt << ", can: " << can;
    } else {
      for (auto nbr : nodes[i].nbrs) {
        int temp = dfs(nodes, nbr, cnt, seen);
        if (temp < 0) return -1;
        can = max(can, temp);
      }
    }
    seen[i] = false;
    cnt[color - 'a']--;
    // LOG(INFO) << "i: " << i << ", return can: " << can;
    return can;
  }
};
