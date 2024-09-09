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
  vector<string> generateParenthesis(int n)
  {
    string cur;
    int left = 0, right = 0;
    vector<string> ans;
    helper(n, ans, left, right, cur);
    return ans;
  }
  void helper(const int n, vector<string>& ans, const int left, const int right, string& cur)
  {
    if (left == right)
    {
      if (left == n)
      {
        ans.push_back(cur);
      }
      else
      {
        cur.push_back('(');
        helper(n, ans, left + 1, right, cur);
        cur.pop_back();
      }
    }
    else if (left > right)
    {
      if (left > n)
        return;
      cur.push_back('(');
      helper(n, ans, left + 1, right, cur);
      cur.pop_back();
      cur.push_back(')');
      helper(n, ans, left, right + 1, cur);
      cur.pop_back();
    }
  }
};
