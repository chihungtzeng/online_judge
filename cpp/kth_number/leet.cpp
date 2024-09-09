#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
  double kth(vector<int>& v, int k)
  {
    int left = *min_element(v.begin(), v.end());
    int right = *max_element(v.begin(), v.end());
    int res = 0;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      int nleq = 0;
      for(auto val: v) {
        if (val <= mid) {
          nleq++;
        }
      }
      if (nleq >= k) {
        res = mid;
        LOG(INFO) << k << " : update res to " << res;
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    return res;
  }
};
