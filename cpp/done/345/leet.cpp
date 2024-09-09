#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
      while ((i <= s.size() - 1) && !is_vowel(s[i])) i++;
      while (j >= 0 && !is_vowel(s[j])) j--;
      if (j >= 0 && i < s.size() && i <= j && is_vowel(s[i]) && is_vowel(s[j])) {
        swap(s[i++], s[j--]);
      }
    }
    return s;
  }
  bool is_vowel(char ch) {
    return bool(
      ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
      ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
  }
};
