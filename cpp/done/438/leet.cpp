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
  vector<int> findAnagrams(string s, string p) {
    vector<int> ret;
    if (s.size() < p.size()) return ret;
    ret.reserve(s.size());
    vector<int> cnt_s(26), cnt_p(26);
    for(size_t i=0; i<p.size(); i++){
      cnt_s[s[i] - 'a']++;
      cnt_p[p[i] - 'a']++;
    }
    if (cnt_s == cnt_p) ret.push_back(0);
    for(size_t i=1, j=p.size(); j<s.size(); j++, i++){
      cnt_s[s[i-1]-'a'] -=1;
      cnt_s[s[j] - 'a'] += 1;
      if (cnt_s == cnt_p) ret.push_back(i);
    }
    return ret;
  }
};
