#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    vector<int> temp(nums);
    sort(temp.begin(), temp.end());
    int nelem = nums.size();

    int i=nelem -1, j=(nelem-1)/2, k=0;
    while (k < nelem) {
      if (k & 1) {
        nums[k++] = temp[i--];
      }
      else {
        nums[k++] = temp[j--];
      }
    }

  }
};
