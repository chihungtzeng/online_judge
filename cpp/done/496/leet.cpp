#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    if (nums1.empty() || nums2.empty()) return ret;

    unordered_map<int, int> idx_of;
    vector<int> gt(nums2.size());
    vector<int> stack;

    stack.push_back(nums2.back());
    gt[nums2.size() - 1] = -1;
    idx_of[nums2.back()] = nums2.size() - 1;
    for (int i = nums2.size() - 2; i >= 0; i--) {
      // LOG(INFO) << "nums2[i] = " << nums2[i] << " stack: " << stack;
      if (stack.back() > nums2[i]) {
        gt[i] = stack.back();
        stack.push_back(nums2[i]);
      } else {
        while (!stack.empty() && stack.back() < nums2[i]) {
          stack.pop_back();
        }
        gt[i] = (stack.empty()) ? -1 : stack.back();
        stack.push_back(nums2[i]);
      }
      idx_of[nums2[i]] = i;
    }
    // LOG(INFO) << gt;
    for (auto v : nums1) {
      auto idx = idx_of[v];
      ret.push_back(gt[idx]);
    }

    return ret;
  }
};
