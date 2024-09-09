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
  string minInteger(string s, int k) {
    vector<vector<int>> pos(10);
    for (int i = s.size() - 1; i >= 0; i--) {
      pos[s[i] - '0'].push_back(i);
    }
    for (int i = 0; i < s.size() && k > 0; i++) {
      int dest = find_rhs_min(s, i, pos, k);
      if (dest > i) {
        pos[s[i] - '0'].push_back(dest);

        auto idx = s[dest] - '0';
        for(int j=0; j<pos[idx].size(); j++){
          if (pos[idx][j] == dest){
            swap(pos[idx][j], pos[idx][pos[idx].size()-1]);
            pos[idx].pop_back();
          }
        }
        k -= dest - i;
        LOG(INFO) << "s: " << s << " swap " << s[i] << " and " << s[dest] << " at index " << i << ", k=" << k;
        swap(s[i], s[dest]);
      }
    }
    return s;
  }
  int find_rhs_min(string& s, const int i, vector<vector<int>>& pos, const int k) {
    int bound = s[i] - '0' - 1;
    for (int j = 0; j <= bound; j++) {
      int candidate = INT_MAX;
      if (pos[j].empty()) continue;
      for (auto idx : pos[j]) {
        if (idx > i && idx - i <= k) {
          candidate = min(candidate, idx);
        }
      }
      if (candidate != INT_MAX) {
        return candidate;
      }
    }
    return -1;
  }
};
