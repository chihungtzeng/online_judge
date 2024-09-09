#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

using range = std::pair<size_t, size_t>;
class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    auto nelem = nums.size();
    std::vector<range> ranges;
    ranges.reserve(nelem);
    for (size_t start = 0; start < nelem;) {
      range r{start, start + 1};
      while (r.second < nelem && nums[r.second] == nums[r.second - 1] + 1) {
        r.second++;
      }
      ranges.emplace_back(r);
      start = r.second;
    }
    std::vector<std::string> ret;
    for (const auto &r : ranges) {
      if (r.second - r.first == 1) {
        ret.emplace_back(std::to_string(nums[r.first]));
      } else {
        auto v1 = nums[r.first];
        auto v2 = nums[r.second - 1];
        ret.emplace_back(std::to_string(v1) + "->" + std::to_string(v2));
      }
    }
    return ret;
  }
};
