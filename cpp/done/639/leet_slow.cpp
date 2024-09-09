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

constexpr int base = 1e9 + 7;
class Solution
{
public:
  int numDecodings(string s)
  {
    unordered_map<uint64_t, int> cache;
    return helper(s, 0, s.size() - 1, cache);
  }

  int helper(string& s, const int from, const int to, unordered_map<uint64_t, int>& cache)
  {
    // LOG(INFO) << s;
    if (from > to)
    {
      return 1;
    }
    if (s[from] == '0')
    {
      return 0;
    }
    if (from == to)
    {
      if (s[from] == '*')
        return 9;
      return 1;
    }
    for (int i = to; i > from; i--)
    {
      char prev = s[i - 1];
      if (s[i] == '0' && (prev != '1' && prev != '2' && prev != '*'))
        return 0;
    }
    if (cache.size() > 10000)
    {
      LOG(INFO) << "cache size: " << cache.size();
    }
    uint64_t key = (from << 16) + (s[from] << 8) + s[from + 1];
    auto it = cache.find(key);
    if (it != cache.end())
    {
      return it->second;
    }
    uint64_t res = 0;
    int next = from + 1;
    if (s[from] == '1' && s[next] == '0')
    {
      res = helper(s, from + 2, to, cache);
    }
    else if (s[from] == '1' && (s[next] >= '1' && s[next] <= '9'))
    {
      res = helper(s, next, to, cache) + helper(s, from + 2, to, cache);
      res %= base;
    }
    else if (s[from] == '1' && s[next] == '*')
    {
      for (char ch = '1'; ch <= '9'; ch++)
      {
        s[next] = ch;
        res += helper(s, from, to, cache);
      }
      res %= base;
      s[next] = '*';

      res %= base;
    }
    else if (s[from] == '2' && (s[next] == '0' || s[next] == '7' || s[next] == '8' || s[next] == '9'))
    {
      res = helper(s, from + 2, to, cache);
    }
    else if (s[from] == '2' && (s[next] >= '1' && s[next] <= '6'))
    {
      res = helper(s, next, to, cache) + helper(s, from + 2, to, cache);
      res %= base;
    }
    else if (s[from] == '2' && s[next] == '*')
    {
      for (char ch = '1'; ch <= '6'; ch++)
      {
        s[next] = ch;
        res += helper(s, from, to, cache);
      }

      s[next] = '7';
      uint64_t temp = helper(s, from, to, cache);
      res += temp * 3;

      res %= base;
      s[next] = '*';

      res %= base;
    }
    else if (s[from] >= '3' && s[from] <= '9')
    {
      res = helper(s, next, to, cache);
    }
    else if (s[from] == '*')
    {
      for (char ch = '1'; ch <= '2'; ch++)
      {
        s[from] = ch;
        res += helper(s, from, to, cache);
      }
      s[from] = '3';
      uint64_t temp = helper(s, from, to, cache);
      res += temp * 7;

      res %= base;
      s[from] = '*';
    }
    // LOG(INFO) << s << ": " << res;

    cache[key] = res;
    return res;
  }
};
