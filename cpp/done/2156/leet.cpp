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
  string subStrHash(string s, int p, int m, int k, int hash)
  {
    const int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
      s[i] = s[i] - 'a' + 1;
    }
    int64_t cur = 0, p_k = 1;
    int can = 0;
    for (int i = n - 1; i >= n - k; i--)
    {
      cur = (cur * p + s[i]) % m;
      p_k = (p_k * p) % m;
    }
    if (cur == hash)
      can = n - k;
    for (int i = n - k - 1; i >= 0; i--)
    {
      cur = (cur * p + m - ((s[i + k] * p_k) % m) + s[i]) % m;
      if (cur == hash)
        can = i;
    }
    string ans = s.substr(can, k);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
      ans[i] = ans[i] - 1 + 'a';
    }
    return ans;
  }
};
