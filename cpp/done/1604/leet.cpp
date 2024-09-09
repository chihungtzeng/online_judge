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
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    unordered_map<string, vector<string>> records;
    for (int i = keyName.size() - 1; i >= 0; i--) {
      records[keyName[i]].push_back(keyTime[i]);
    }
    vector<string> ans;
    for (auto& [name, atimes] : records) {
      if (satisfy(atimes)) {
        ans.push_back(name);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
  bool satisfy(vector<string>& atimes) {
    vector<int> hms;
    for (auto& t : atimes) {
      int h = stoi(t.substr(0, 2));
      int m = stoi(t.substr(3, 2));
      hms.push_back(h * 60 + m);
    }
    sort(hms.begin(), hms.end());
    for (int i = 0; i < hms.size(); i++) {
      int start = hms[i];
      int end = start + 60;
      auto it = upper_bound(hms.begin() + i, hms.end(), end);
      int idx = it - hms.begin();
      if (idx - i >= 3) return true;
    }
    return false;
  }
};
