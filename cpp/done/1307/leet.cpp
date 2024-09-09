#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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
#define DEBUG 0

class Solution {
 public:
  unordered_set<char> start_chars_, all_chars_;
  unordered_map<char, int> mvals_;

  bool isSolvable(vector<string>& words, string result) {
    for (auto& w : words) {
      if (w.size() > result.size()) return false;
      for (auto ch : w) {
        all_chars_.insert(ch);
      }
      if (w.size() > 1) {
        start_chars_.insert(w[0]);
      }
      reverse(w.begin(), w.end());
    }
    for (auto ch : result) {
      all_chars_.insert(ch);
    }
    if (result.size() > 1) {
      start_chars_.insert(result[0]);
    }
    reverse(result.begin(), result.end());

#if DEBUG
    for (auto ch : start_chars_) {
      LOG(INFO) << "start ch: " << ch;
    }
    for (auto ch : all_chars_) {
      LOG(INFO) << "all ch: " << ch;
    }

#endif

    vector<bool> used_(10, false);
    mvals_.clear();

    return dfs(words, result, used_, 0, 0);
  }

  vector<int> get_avail_digits(char ch, vector<bool>& used) {
    vector<int> ret;
    int since = 0;
    if (start_chars_.find(ch) != start_chars_.end()) {
      since = 1;
    }
    for (int i = since; i < 10; i++) {
      if (!used[i]) ret.push_back(i);
    }
    return ret;
  }

  bool dfs(vector<string>& words, string& result, vector<bool>& used, int carry,
           int pos) {
#if DEBUG
    for (auto& [ch, val] : mvals_) {
      cout << ch << ":" << val << ", ";
    }
    cout << endl;

#endif
    if (pos == result.size()) {
#if DEBUG
      string token;
      for (string& w : words) {
        token.clear();
        for (auto ch : w) {
          token.push_back('0' + mvals_[ch]);
        }
        reverse(token.begin(), token.end());
        cout << token << "+";
      }
      token.clear();
      for (auto ch : result) {
        token.push_back('0' + mvals_[ch]);
      }
      reverse(token.begin(), token.end());
      cout << " = " << token << endl;
#endif
      return bool(carry == 0 && mvals_.size() == all_chars_.size());
    }

    int lhs = carry;
    for (auto& w : words) {
      if (pos >= w.size()) {
        continue;
      }
      char ch = w[pos];
      if (mvals_.find(ch) == mvals_.end()) {
        auto avail_digits = get_avail_digits(ch, used);
        if (avail_digits.empty()) {
          return false;
        }
        for (auto val : avail_digits) {
#if DEBUG
          LOG(INFO) << w << ": pick " << val << " for " << ch;
#endif
          used[val] = true;
          mvals_[ch] = val;
          auto ret = dfs(words, result, used, carry, pos);
          if (ret) return true;
          used[val] = false;
          mvals_.erase(ch);
#if DEBUG
          LOG(INFO) << w << ": erase " << val << " for " << ch;
#endif
        }
        return false;
      } else {
        lhs += mvals_[ch];
#if DEBUG
        LOG(INFO) << ch << ": add " << mvals_[ch] << " lhs: " << lhs;
#endif
      }
    }
    char ch = result[pos];
    if (mvals_.find(ch) == mvals_.end()) {
      auto avail_digits = get_avail_digits(ch, used);
      if (avail_digits.empty()) {
        return false;
      }
      for (auto val : avail_digits) {
#if DEBUG
        LOG(INFO) << result << ": pick " << val << " for " << ch;
#endif
        used[val] = true;
        mvals_[ch] = val;
        auto ret = dfs(words, result, used, carry, pos);
        if (ret) return true;
        used[val] = false;
        mvals_.erase(ch);
#if DEBUG
        LOG(INFO) << result << ": erase " << val << " for " << ch;
#endif
      }
      return false;
    } else {
#if DEBUG
      LOG(INFO) << "carry:" << carry << " lhs: " << lhs
                << ", rhs: " << mvals_[ch] << ", pos: " << pos;
#endif
      if (lhs % 10 != mvals_[ch])
        return false;
      else
        return dfs(words, result, used, lhs / 10, pos + 1);
    }
  }
};
