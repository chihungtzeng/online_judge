#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
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
  bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
    int g = groups.size() - 1;
    int j = nums.size() - 1;
    while (j >= 0 && g >= 0) {
      if (match_group(groups[g], nums, j)) {
        j -= groups[g].size();
        g--;
      } else {
        j--;
      }
    }
    return g < 0;
  }
  bool match_group(vector<int> &group, vector<int> &nums, int j) {
    const int gs = group.size();
    if (gs > j + 1)
      return false;
    const int jstart = j - gs + 1;
    for (int i = 0; i < gs; i++) {
      if (group[i] != nums[jstart + i])
        return false;
    }
    return true;
  }
};
