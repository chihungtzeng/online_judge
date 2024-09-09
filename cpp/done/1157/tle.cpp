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
class MajorityChecker {
 public:
  vector<unordered_map<int, int>> psum;
  MajorityChecker(vector<int>& arr) : psum(arr.size()) {
    for (int i = 0; i < arr.size(); i++) {
      if (i > 0) {
        psum[i] = psum[i - 1];
      }
      psum[i][arr[i]]++;
    }
#if 0
    for(int i=0; i<arr.size(); i++){
      LOG(INFO) << "psum of " << i;
      for(auto& [val, freq]: psum[i]) {
        std::cout << val << ":" << freq << " ";
      }
      std::cout << '\n';
    }
#endif
  }

  int query(int left, int right, int threshold) {
    int ans = -1;
    for (auto& [val, freq] : psum[right]) {
      int nappear = 0;
      if (left == 0) {
        nappear = freq;
      } else {
        nappear = freq - psum[left - 1][val];
      }

      if (nappear >= threshold) {
        ans = val;
      }
    }
    return ans;
  }
};

