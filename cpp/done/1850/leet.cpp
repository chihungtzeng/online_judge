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
  int getMinSwaps(string num, int k) {
    string org = num;
    while(k--){
      next_permutation(num.begin(), num.end());
    }
    int ans = 0;
//    LOG(INFO) << num;
    for(int i=0; i<num.size(); i++){
      if (org[i] == num[i]){
        continue;
      }
//      LOG(INFO) << "mismatch at pos i: " << i << ", org[i]=" << org[i];
      int j = i+1;
      while(j <num.size() && num[j] != org[i]){
        j++;
      }
      ans += j-i;
      for(int k=j; k>i; k--){
        swap(num[k], num[k-1]);
      }
//      LOG(INFO) << "After swap, num: " << num;
    }
    return ans;
  }
};
