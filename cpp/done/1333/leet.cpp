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
  vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<int> idxes;
    for (int i = restaurants.size() - 1; i >= 0; i--) {
      auto& r = restaurants[i];

      bool match = true;
      if (veganFriendly && r[2] == 0) match = false;
      if (!match) continue;
      if (r[3] <= maxPrice && r[4] <= maxDistance) idxes.push_back(i);
    }
    vector<pair<int, int>> temp;
    for (auto i : idxes) {
      temp.push_back({restaurants[i][0], restaurants[i][1]});
    }
    auto cmp = [](const auto& a, const auto& b) {
      if (a.second != b.second) return a.second > b.second;
      return a.first > b.first;
    };
    sort(temp.begin(), temp.end(), cmp);
    vector<int> ans;
    for (auto& [id, rating] : temp) ans.push_back(id);
    return ans;
  }
};
