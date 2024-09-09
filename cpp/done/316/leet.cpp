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
  string removeDuplicateLetters(string s) {
    vector<int> cnt(26);
    for(auto ch: s){
      cnt[ch-'a'] += 1;
    }
    vector<char> stack;
    vector<bool> within(26, false);
    for(auto ch: s){
      cnt[ch-'a'] -= 1;
      if (within[ch-'a']){
        continue;
      }
      while(!stack.empty() && cnt[stack.back() - 'a'] > 0 && stack.back() > ch) {
        within[stack.back() - 'a'] = false;
        stack.pop_back();
      }
      stack.push_back(ch);
      within[ch-'a'] = true;
    }
    return string{stack.begin(), stack.end()};
  }
};
