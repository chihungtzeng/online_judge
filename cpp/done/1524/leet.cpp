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
  int numOfSubarrays(vector<int>& arr) {
    int nodd = 0, neven = 0, s = 0, ret = 0;
    for (int i = 0; i < arr.size(); i++) {
      s += arr[i];
      if (s & 1) {
        ret += 1 + neven;
        nodd++;
      } else {
        ret += nodd;
        neven++;
      }

      ret = ret % 1000000007;
    }
    return ret;
  }
};
