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

vector<string> digits_s{"zero", "one", "two",   "three", "four",
                        "five", "six", "seven", "eight", "nine"};
vector<map<char, int>> digits_cnt(10);
map<char, int> all_digits_cnt;

class Solution {
 public:
  void init_cnt() {
    for (int i = 0; i < 10; i++) {
      for (auto ch : digits_s[i]) {
        auto it = digits_cnt[i].find(ch);
        if (it == digits_cnt[i].end()) {
          digits_cnt[i][ch] = 1;
        } else {
          it->second += 1;
        }

        it = all_digits_cnt.find(ch);
        if (it == all_digits_cnt.end()) {
          all_digits_cnt[ch] = 1;
        } else {
          it->second += 1;
        }
      }
    }

    for (const auto& [key, val] : all_digits_cnt) {
      cout << key << ": " << val << ", ";
    }
    cout << '\n';
    for (auto& [key, val] : all_digits_cnt) {
      val--;
      cout << key << ": " << val << ", ";
    }
    cout << '\n';
    for (const auto& [key, val] : all_digits_cnt) {
      cout << key << ": " << val << ", ";
    }
    cout << '\n';
  }
  string originalDigits(string s) {
    if (s.empty()){
      return "";
    }
    if (digits_cnt[0].count('z') == 0) {
      init_cnt();
    }
    return "";
    string ret;
    map<char, int> s_cnt;
    for(auto ch: s){
      auto it = s_cnt.find(ch);
      if (it == s_cnt.end()){
        s_cnt[ch] = 1;
      } else {
        it->second += 1;
      }
    }
    bool done = false;
    while (!done){
      for(int i=0; i<10; i++){
        bool found = false;
        int val = -1;
        for(const auto& [ch, cnt]: digits_cnt[i]){
          if (cnt == 1 && all_digits_cnt[ch] == 1 && s_cnt.count(ch) > 0) {
            val = i;
            found = true;
          }
        }
        if (found) {
          LOG(INFO) << "catch " << val;
          ret.push_back(val + '0');
          for(auto& [ch, cnt]: digits_cnt[val]){
            s_cnt[ch] -= cnt;
            if (s_cnt[ch] == 0) {
              s_cnt.erase(ch);
            }
          }
        }
      }
      if (s_cnt.empty()){
        done = true;
      }
    }

    return "";
  }
};
