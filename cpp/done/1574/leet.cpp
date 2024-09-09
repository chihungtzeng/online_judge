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
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1, ans = 0;
    const int n = arr.size();
    while (left + 1 < arr.size() && arr[left] <= arr[left + 1]) left++;
    if (left == arr.size() - 1) return 0;
    while (right > left && arr[right - 1] <= arr[right]) right--;
    ans = min(right, n - left - 1);
    int i = 0, j = right;
    while (i <= left && j < n) {
      if (arr[i] <= arr[j]) {
        i++;
      } else {
        j++;
      }
      ans = min(ans, j - i);
    }
    return ans;
  }
};
