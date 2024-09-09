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
  vector<int> getStrongest(vector<int>& arr, int k) {
    vector<int> ret(k);
    auto m = median_of(arr);
    priority_queue<ipair> pq;
    for (auto v : arr) {
      pq.push({abs(v - m), v});
    }
    for (int i = 0; i < k; i++) {
      ret[i] = pq.top().second;
      pq.pop();
    }
    return ret;
  }
  int median_of(vector<int>& arr) {
    int k = (arr.size() - 1) / 2;
    nth_element(arr.begin(), arr.begin() + k, arr.end());
    return arr[k];
  }
};
