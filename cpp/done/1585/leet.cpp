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
  bool isTransformable(string s, string t) {
    const int n = s.size();
    string s1 = s, t1 = t;
    for (char ch = '9'; ch >= '0'; ch--) {
      vector<int> tpos, spos;
      for (int i = s1.size() - 1; i >= 0; i--) {
        if (s1[i] == ch) spos.push_back(i);
        if (t1[i] == ch) tpos.push_back(i);
      }
      if (spos.size() != tpos.size()) return false;
      for (int i = spos.size() - 1; i >= 0; i--) {
        if (spos[i] > tpos[i]) return false;
      }
      string s2, t2;
      for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != ch) s2.push_back(s1[i]);
        if (t1[i] != ch) t2.push_back(t1[i]);
      }
      s1 = s2;
      t1 = t2;
    }
    return true;
  }
};
