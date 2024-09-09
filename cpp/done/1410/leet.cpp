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
  string entityParser(string text) {
    string ans;
    int i = 0;
    while (i < text.size()) {
      if (text[i] == '&') {
        if (text.substr(i, 6) == "&quot;") {
          ans.push_back('"');
          i += 6;
        } else if (text.substr(i, 6) == "&apos;") {
          ans.push_back('\'');
          i += 6;
        } else if (text.substr(i, 5) == "&amp;") {
          ans.push_back('&');
          i += 5;
        } else if (text.substr(i, 4) == "&gt;") {
          ans.push_back('>');
          i += 4;
        } else if (text.substr(i, 4) == "&lt;") {
          ans.push_back('<');
          i += 4;
        } else if (text.substr(i, 7) == "&frasl;") {
          ans.push_back('/');
          i += 7;
        } else {
          ans.push_back(text[i]);
          i++;
        }
      } else {
        ans.push_back(text[i]);
        i++;
      }
    }
    return ans;
  }
};

