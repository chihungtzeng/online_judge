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
  vector<int> nums_;
  vector<int> temp_;
  Solution(vector<int>& nums) : nums_(nums), temp_(nums) { srand(time(NULL)); }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return nums_; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    if (temp_.size() <= 1) {
      return temp_;
    }
    for (size_t i = 0, nelem = temp_.size(); i < nelem; i++) {
      size_t j = rand() % nelem;
      size_t k = rand() % nelem;
      std::swap(temp_[j], temp_[k]);
    }
    return temp_;
  }
};
