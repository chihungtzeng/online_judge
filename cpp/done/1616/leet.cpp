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
  bool checkPalindromeFormation(string a, string b) {
    if (is_palindrome(a) || is_palindrome(b)) return true;

    if (can_split_into_palindrome(a, b) || can_split_into_palindrome(b, a))
      return true;
    return false;
  }
  bool can_split_into_palindrome(string& a, string& b) {
    int i = 0, j = a.size() - 1;
    const char* aptr = a.c_str();
    const char* bptr = b.c_str();
    while (i < j) {
      if (aptr[i] != bptr[j]) {
        string t = a.substr(i, j - i + 1);
        if (is_palindrome(t)) return true;

        t = b.substr(i, j - i + 1);
        if (is_palindrome(t))
          return true;
        else
          return false;
      }
      i++;
      j--;
    }
    return true;
  }
  bool is_palindrome(string& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) return false;
      i++;
      j--;
    }
    // LOG(INFO) << s << " is palindrome";
    return true;
  }
};
