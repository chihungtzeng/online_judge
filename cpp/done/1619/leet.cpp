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
class Solution {
 public:
  double trimMean(vector<int>& arr) {
    const int n = arr.size();
    int ntrim = n * 0.05;
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = ntrim, last = n - ntrim; i < last; i++) {
      sum += arr[i];
    }
    return sum / (n - ntrim * 2);
  }
};
