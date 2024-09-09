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

using ipair = pair<int, int>;
class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;
    vector<ipair> edges;
    edges.reserve(buildings.size() * 2);
    for (auto& bld : buildings) {
      edges.emplace_back(ipair{bld[0], -bld[2]});
      edges.emplace_back(ipair{bld[1], bld[2]});
    }
    sort(edges.begin(), edges.end());
    multiset<int> ms;
    ms.insert(0);
    int prev = 0;
    for (auto [x, height] : edges) {
      if (height < 0)
        ms.insert(-height);
      else
        ms.erase(ms.find(height));

      int cur = *(ms.rbegin());
      if (prev != cur) {
        ans.emplace_back(vector<int>{x, cur});
      }
      prev = cur;
    }
    return ans;
  }
};
