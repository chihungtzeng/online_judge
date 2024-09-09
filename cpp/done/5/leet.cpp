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
  string longestPalindrome(string s)
  {
    int n = s.size();
    string ans;
    vector<vector<bool>> p(n, vector(n, false));
    for (int l = 0; l < n; l++)
    {
      for (int i = 0; i < n; i++)
      {
        int j = i + l;
        if (j >= n)
          break;

        if (s[i] == s[j])
        {
          if (l <= 1)
            p[i][j] = true;
          else
            p[i][j] = p[i + 1][j - 1];
        }
        else
        {
          p[i][j] = false;
        }

        if (p[i][j] && l + 1 > ans.size())
        {
          ans = s.substr(i, l + 1);
        }
      }
    }
    return ans;
  }
};
