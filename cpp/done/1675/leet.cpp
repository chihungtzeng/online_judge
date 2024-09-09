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
  int minimumDeviation(vector<int>& nums) {
    for(int i=0, n=nums.size(); i<n; i++){
      if (nums[i] & 1) {
        nums[i] <<= 1;
      }
    }
    set<int> s(nums.begin(), nums.end());
    int ans = INT_MAX;
    bool done = false;
    while (!done) {
      int big = *(s.rbegin());
      int small = *(s.begin());
      ans = min(ans, big - small);
      if ((big & 1) == 0){
        s.erase(big);
        s.insert(big >> 1);
      } else {
        done = true;
      }
    }
    return ans;
  }
};
