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
#define DEBUG 0

constexpr int base = 1e9 + 7;
vector<int> cache1(256);
unordered_map<string, int> cache2;
class Solution
{
public:
  int numDecodings(string s)
  {
    build_cache();
    uint64_t f0 = 1, f1 = cache1[s.back()], f2 = 0;
    for (int i = s.size() - 2; i >= 0; i--)
    {
      f2 = f0 * cache2[s.substr(i, 2)] + f1 * cache1[s[i]];
      f0 = f1;
      f1 = f2 % base;
      // LOG(INFO) << f1;
    }
    return f1;
  }
  void build_cache()
  {
    for (int i = 1; i <= 9; i++)
    {
      cache1['0' + i] = 1;
    }
    cache1['*'] = 9;

    string s = "0";
    for (int i = '0'; i <= '9'; i++)
    {
      s.push_back(i);
      cache2[s] = 0;
      s.pop_back();
    }
    for (int i = 10; i <= 99; i++)
    {
      if (i <= 26)
        cache2[to_string(i)] = 1;
      else
        cache2[to_string(i)] = 0;
    }

    cache2["0*"] = 0;
    cache2["1*"] = 9;
    cache2["2*"] = 6;
    for (int i = 3; i <= 9; i++)
    {
      cache2[to_string(i) + "*"] = 0;
    }

    for (int i = 0; i <= 9; i++)
    {
      if (i <= 6)
        cache2["*" + to_string(i)] = 2;
      else
        cache2["*" + to_string(i)] = 1;
    }
    cache2["**"] = 15;
#if DEBUG
    for (auto& [key, val] : cache2)
    {
      LOG(INFO) << key << " : " << val;
    }
#endif
  }
};
