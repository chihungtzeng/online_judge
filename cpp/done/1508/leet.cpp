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
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    for (int i = 0; i < n; i++) {
      pq.push({nums[i], i + 1});
    }
    int nvisit = 0;
    int ret = 0;
    while (nvisit < right) {
      auto cur = pq.top();
      nvisit++;
      pq.pop();
      if (nvisit >= left) {
        ret = (cur.first + ret) % 1000000007;
      }
      if (cur.second < n) {
        pq.push({cur.first + nums[cur.second], cur.second + 1});
      }
    }
    return ret;
  }
};
