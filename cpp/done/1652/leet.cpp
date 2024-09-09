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
  vector<int> decrypt(vector<int>& code, int k) {
    const int n = code.size();
    if (k == 0) {
      return vector<int>(n);
    }
    vector<int> arr(2 * n);
    for (int i = 0; i < 2; i++) {
      for (int j = i * n, start = i * n, end = (i + 1) * n; j < end; j++) {
        arr[j] = code[j - start];
      }
    }
    for (int i = 1, j = n + n; i < j; i++) {
      arr[i] += arr[i - 1];
    }
    vector<int> ret(n);
    if (k > 0) {
      for (int i = 0; i < n; i++) {
        ret[i] = arr[i + k] - arr[i];
      }
    } else {
      for (int i = 0; i < n; i++) {
        ret[i] = arr[n + i - 1] - arr[n + i - 1 + k];
      }
    }
    return ret;
  }
};
