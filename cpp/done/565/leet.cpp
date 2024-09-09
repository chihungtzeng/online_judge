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
  int arrayNesting(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<bool> visited(nums.size(), false);
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i]) continue;
      int cnt = 1;
      visited[i] = true;
      int pos = i;
      bool done = false;
      while (!done) {
        pos = nums[pos];
        if (visited[pos])
          done = true;
        else {
          cnt++;
          visited[pos] = true;
        }
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};
