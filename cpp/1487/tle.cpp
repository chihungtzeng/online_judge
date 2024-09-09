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
  vector<string> getFolderNames(vector<string>& names) {
    unordered_set<string> seen;
    vector<string> ret;
    for (auto& s : names) {
      auto it = seen.find(s);
      if (it == seen.end()) {
        seen.insert(s);
        ret.push_back(s);
      } else {
        int sn = 1;
        bool done = false;
        while (!done) {
          string uname = s + '(' + to_string(sn) + ')';
          if (seen.count(uname) == 0) {
            done = true;
            seen.insert(uname);
            ret.push_back(uname);
          } else {
            sn++;
          }
        }
      }
    }
    return ret;
  }
};
