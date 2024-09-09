#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
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
  int countSegments(string s) {
    char prev = ' ';
    int cnt = 0;
    for(auto ch: s) {
      if ((ch != ' ') && (prev == ' ')) {
        cnt++;
      }
      prev = ch;
    }
    return cnt;
  }
};
