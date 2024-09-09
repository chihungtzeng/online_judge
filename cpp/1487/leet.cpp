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
    unordered_map<string, set<int>> base2ext;
    vector<string> ret;
    for (auto& name : names) {
      string base;
      auto it = base2ext.find(name);
      if (it == base2ext.end()) {
        base2ext[name] = set<int>();
        ret.push_back(name);
        int digits = split(name, base);
        if (digits) {
          base2ext[base].insert(digits);
        }
      } else {
        int sn = 1;
        while (it->second.count(sn) > 0) {
          sn++;
        }
        it->second.insert(sn);
        string uname = name + '(' + to_string(sn) + ')';
        base2ext[uname] = set<int>();
        ret.emplace_back(uname);
      }
    }
    return ret;
  }
  int split(string& name, string& base) {
    if (name.back() != ')') return 0;
    auto pos = name.rfind('(');
    for (int i = name.size() - 2; i > pos; i--) {
      if (!isdigit(name[i])) return 0;
    }
    string digits = name.substr(pos + 1, name.size() - pos - 1);
    base = name.substr(0, pos);
    return stoi(digits);
  }
};
