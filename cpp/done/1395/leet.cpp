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
  int numTeams(vector<int>& rating) {
    int n1 = helper(rating);
    reverse(rating.begin(), rating.end());
    return n1 + helper(rating);
  }
  int helper(vector<int>& rating) {
    const int n = rating.size();
    vector<int> left(n), right(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int left = 0, right = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (rating[j] < rating[i]) left++;
      }
      for (int j = i + 1; j < n; j++) {
        if (rating[j] > rating[i]) right++;
      }
      ans += left * right;
    }
    return ans;
  }
};
