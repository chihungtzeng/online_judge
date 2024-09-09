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
  int dayOfYear(string date) {
    vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    if (is_lunar_year(year)) {
      days[2]++;
    }
    int ans = 0;
    for (int i = 1; i < month; i++) {
      ans += days[i];
    }
    ans += day;
    return ans;
  }
  bool is_lunar_year(int y) {
    if (y % 4 != 0) return false;
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return true;
  }
};
