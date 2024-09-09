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

struct Record {
  int index;
  string src;
  string dest;
  Record(int index, string s, string t) : index(index), src(s), dest(t) {}
  Record() : index(0), src(""), dest("") {}
  bool operator<(const Record& b) const { return index < b.index; }
};

class Solution {
 public:
  string findReplaceString(string s, vector<int>& indexes,
                           vector<string>& sources, vector<string>& targets) {
    int inc = 0;

    vector<Record> records(indexes.size());
    for (int i = indexes.size() - 1; i >= 0; i--) {
      records[i] = Record(indexes[i], sources[i], targets[i]);
    }

    sort(records.begin(), records.end());
    for (int i = 0; i < indexes.size(); i++) {
      string t = s.substr(records[i].index + inc, records[i].src.size());
      // LOG(INFO) << "t: " << t << " targets[i]: " << targets[i];
      if (t == records[i].src) {
        s = s.substr(0, records[i].index + inc) + records[i].dest +
            s.substr(records[i].index + inc + records[i].src.size());
        inc = inc + (static_cast<int>(records[i].dest.size()) -
                     records[i].src.size());
      }
    }
    return s;
  }
};
