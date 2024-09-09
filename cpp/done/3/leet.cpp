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
  int lengthOfLongestSubstring(string s)
  {
    int j = 0;
    vector<bool> seen(256, false);
    int ans = 0;
    const int n = s.size();
    for (int i = 0; i < n; i++)
    {
      if (seen[s[i]])
      {
        while (j < i && s[j] != s[i])
        {
          seen[s[j]] = false;
          j++;
        }
        j++;
      }
      ans = max(i - j + 1, ans);
      seen[s[i]] = true;
    }
    return ans;
  }
};
