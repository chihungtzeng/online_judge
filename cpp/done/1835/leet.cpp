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
  int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    auto cnt1 = bit_counts_of(arr1);
    auto cnt2 = bit_counts_of(arr2);
    int ret = 0;
    for(int i=0; i<31; i++){
      int bit = 0;
      if (cnt2[i] % 2 == 1 && cnt1[i] % 2 == 1) {
        bit = 1;
      }
      ret += (bit << i);
    }
    return ret;
  }

  vector<int> bit_counts_of(vector<int>& a){
    vector<int> cnt(32, 0);
    for(int val: a){
      for(int i=0; i<31; i++){
        cnt[i] += (val >> i) & 1;
      }
    }
    return cnt;
  }
};
