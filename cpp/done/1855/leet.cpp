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
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size(), m = nums2.size();
    int j=0;
    int ans = 0;
    for(int i=0; i<n; i++){
      while (j < m && nums1[i] <= nums2[j]){
        j++;
      }
      ans = max(ans, j - i - 1);
    }
    return ans;
  }
};

#if 0
  int best_j(vector<int>& nums1, vector<int>& nums2, int i)
  {
    int best_j = -1;
    while (left <= right)
    {
      int mid = (left + right) >> 1;
      if (nums2[mid] >= nums1[i]){
        best_j = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return best_j;
  }
#endif  

