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
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    vector<int> l(nums.size()), cnt(nums.size());
    l[0] = 1;
    cnt[0] = 1;
    int lis = 0;
    for(int i=1; i<nums.size(); i++){
      int cur_l = 1;
      int cur_cnt = 1;
      for(int j=0; j<i; j++){
        if (nums[j] < nums[i]){
          if (l[j] >= cur_l){
            cur_l = l[j] + 1;
            cur_cnt = cnt[j];
          } else if (l[j] == cur_l - 1){
            cur_cnt += cnt[j];
          }
        }
      }
      l[i] = cur_l;
      cnt[i] = cur_cnt;
      if (cur_l > lis) lis = cur_l;
    }
    int ret = 0;
    for(int i=0; i<nums.size(); i++){
      if (l[i] == lis) {
        ret += cnt[i];
      }
    }
    return ret;
  }

};
