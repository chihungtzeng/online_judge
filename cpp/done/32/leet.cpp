#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    auto s1 = rm(s, '(');
    reverse(s1.begin(), s1.end());
    auto s2 = rm(s1, ')');
    int ans = 0, cnt = 0;
    for (auto ch : s2)
    {
      if (ch == '(' || ch == ')')
      {
        cnt++;
      }
      else
      {
        ans = max(ans, cnt);
        cnt = 0;
      }
      //  LOG(INFO) << "current cnt: " << cnt;
    }
    ans = max(ans, cnt);
    return ans;
  }

  string rm(string& s, char left)
  {
    char right = (left == '(') ? ')' : '(';
    string res;
    int cnt = 0;
    for (auto ch : s)
    {
      if (ch == left)
      {
        cnt++;
        res.push_back(ch);
      }
      else if (ch == right && cnt > 0)
      {
        res.push_back(ch);
        cnt--;
      }
      else
      {
        res.push_back('*');
      }
    }

    // LOG(INFO) << "input: " << s << ", output: " << res << ", left " << left;
    return res;
  }
};
