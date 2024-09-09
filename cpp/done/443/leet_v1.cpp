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
  int compress(vector<char>& chars) {
    if (chars.size() < 2) {
      return chars.size();
    }
    int cur = 0;
    int count = 1;
    for (size_t i = 1; i < chars.size(); i++) {
      if (chars[i] == chars[i - 1]) {
        count++;
      } else {
        chars[cur++] = chars[i - 1];
        if (count > 1) {
          auto s = std::to_string(count);
          for (auto ch : s) {
            chars[cur++] = ch;
          }
        }
        count = 1;
      }
    }
    chars[cur++] = chars.back();
    if (count > 1) {
      auto s = std::to_string(count);
      for (auto ch : s) {
        chars[cur++] = ch;
      }
    }
    chars.erase(chars.begin() + cur, chars.end());
    return chars.size();
  }
};
