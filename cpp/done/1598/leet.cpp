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
  const string up{"../"}, cur{"./"};
  int minOperations(vector<string>& logs) {
    vector<string> stack;
    for (auto& s : logs) {
      if (s == up) {
        if (!stack.empty()) {
          stack.pop_back();
        }
      } else if (s != cur) {
        stack.emplace_back(s);
      }
    }
    return stack.size();
  }
};
