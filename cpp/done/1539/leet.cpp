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
  int findKthPositive(vector<int>& arr, int k) {
    // int nmiss, last_miss
    int last_miss = 0, nmiss = arr[0] - 1;
    if (nmiss >= k) {
      return k;
    }
    last_miss = arr[0] + 1;
    for (int i = 1; i < arr.size(); i++) {
      nmiss += (arr[i] - arr[i - 1]) - 1;
      if (nmiss >= k) {
        return arr[i] - (nmiss -k) - 1;
      }
      last_miss = arr[i] + 1;
    }
    return last_miss + (k - nmiss) - 1;
  }
};
