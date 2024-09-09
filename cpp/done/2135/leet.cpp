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
  int wordCount(vector<string>& startWords, vector<string>& targetWords)
  {
    unordered_set<int> words;
    for (auto& w : startWords)
    {
      words.insert(to_int(w));
    }
    int ans = 0;
    for (auto& w : targetWords)
    {
      int hash = to_int(w);
      int find = 0;
      for (int i = 25; i >= 0 && !find; i--)
      {
        if ((hash >> i) & 1)
        {
          auto it = words.find(hash ^ (1 << i));
          if (it != words.end())
            find = 1;
        }
      }
      ans += find;
    }
    return ans;
  }
  int to_int(string& w)
  {
    int res = 0;
    for (auto ch : w)
    {
      res |= (1 << (ch - 'a'));
    }
    return res;
  }
};
