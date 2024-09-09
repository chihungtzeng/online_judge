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
  bool canTransform(string start, string end) {
    string s1, s2;
    int i = 0, j = 0;
    int n = start.size();
    for (auto ch : start) {
      if (ch != 'X') s1.push_back(ch);
    }
    for (auto ch : end) {
      if (ch != 'X') s2.push_back(ch);
    }
    if (s1 != s2) return false;
    while (i < n && j < n) {
      while (start[i] == 'X') i++;
      while (end[j] == 'X') j++;
      if (i == n || j == n) break;
      if (start[i] == 'R' && i > j) return false;
      if (start[i] == 'L' && i < j) return false;
      i++;
      j++;
    }
    return true;
  }
};
