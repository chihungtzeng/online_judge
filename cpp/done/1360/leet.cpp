#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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
  int daysBetweenDates(string date1, string date2) {
    if (date1 > date2) swap(date1, date2);
    int y1, m1, d1, y2, m2, d2;
    parse(date1, y1, m1, d1);
    parse(date2, y2, m2, d2);
    //    LOG(INFO) << "date1: " << date1 << " date2: " << date2;
    return days_since(y2, m2, d2) - days_since(y1, m1, d1);
  }

  bool is_leap_year(int y) {
    if (y % 4 == 0) {
      return (y % 100 != 0);
    }
    return false;
  }

  int days_since(int y, int m, int d) {
    const vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nleap_year = y / 4 - y / 100 + y / 400;
    int ans = (y - 1) * 365;
    for (int i = 0; i < m; i++) {
      ans += days[i];
    }
    ans += d;
    if (is_leap_year(y)) {
      if (m >= 3) {
        ans += nleap_year;
      } else {
        ans += nleap_year - 1;
      }
    } else {
      ans += nleap_year;
    }
    return ans;
  }

  void parse(string& d, int& year, int& month, int& day) {
    year = stoi(d.substr(0, 4));
    month = stoi(d.substr(5, 2));
    day = stoi(d.substr(8, 2));
  }
};
