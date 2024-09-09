#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int longestSubstring(string s, int k) {
    vector<int> freq(26);
    if (s.empty()) {
      return 0;
    }
    size_t ssize = s.size();
    for(size_t i=0; i<ssize; i++){
      freq[s[i] - 'a']++;
    }
    int left=0, right=ssize-1;
    int i=0, j=right;
    while (i <= j)
    {
      if (freq[s[j]-'a'] < k) {
        while(right >= j && right >= 0) {
          freq[s[right] - 'a']--;
          right--;
        }
        j = right;
        i = left;
      }
      else if (freq[s[i] - 'a'] < k) {
        while (left <= i && left < ssize) {
          freq[s[left] - 'a']--;
          left++;
        }
        i = left;
        j = right;
      } else {
        i++;
        j--;
      }
    }
//    LOG(INFO) << "right: " << right << ", left: " << left << ", s=" << s.substr(left, right - left + 1);
//    LOG(INFO) << freq;

    return right - left + 1;
  }
};
