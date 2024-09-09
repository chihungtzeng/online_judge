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

using ipair = pair<int, int>;
class Solution {
 public:
  vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
    const int n = nums.size();
    vector<vector<int>> nbrs(n);
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
    }
    vector<vector<int>> gcds(51, vector<int>(51));
    for(int i=1; i<51; i++){
      for(int j=i; j<51; j++){
        gcds[i][j] = gcd(i, j);
        gcds[j][i] = gcds[i][j];
      }
    }
    vector<int> ans(n, -1);
    vector<ipair> stack{{0,0}};

    for (int i = 1; i < n; i++) {
      int p = parents[i];
      while (p >= 0) {
        if (gcds[nums[i]][nums[p]] == 1) {
          ans[i] = p;
          break;
        } else {
          p = parents[p];
        }
      }
    }
    return ans;
  }
};
