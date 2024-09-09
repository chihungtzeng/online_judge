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
  int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                            int num_wanted, int use_limit) {
    unordered_map<int, int> quota;
    for (auto ell : labels) {
      quota[ell] = use_limit;
    }

    vector<ipair> items;
    const int n = values.size();
    for (int i = 0; i < n; i++) {
      items.emplace_back(values[i], labels[i]);
    }
    sort(items.begin(), items.end());
    int ans = 0;
    int nchoose = 0;
    for (int i = n - 1; i >= 0 && nchoose < num_wanted; i--) {
      auto [value, label] = items[i];
      if (quota[label] > 0) {
        ans += value;
        quota[label]--;
        nchoose++;
      }
    }
    return ans;
  }
};
