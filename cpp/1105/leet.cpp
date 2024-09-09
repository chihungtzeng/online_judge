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
  int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
    int right = 0;
    for (auto& book : books) {
      right += book[1];
    }
    int left = 0;
    int ans = right;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (can_fit(books, shelf_width, mid)) {
      LOG(INFO) << "can fit into height " << mid;
        ans = mid;
        right = mid - 1;
      } else {
      LOG(INFO) << "cannot fit into height " << mid;
        left = mid + 1;
      }
    }
    return ans;
  }
  bool can_fit(vector<vector<int>>& books, int shelf_width, int max_height) {
    int total_height = 0, cur_height = 0;
    int width = 0;

    for (auto& book : books) {
      int bw = book[0], bh = book[1];
      if (width + bw > shelf_width) {
        total_height += cur_height;
        cur_height = bh;
        width = bw;
      } else {
        cur_height = max(cur_height, bh);
        width += bw;
      }
    }
    total_height += cur_height;
    return total_height <= max_height;
  }
};
