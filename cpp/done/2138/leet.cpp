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
  vector<string> divideString(string s, int k, char fill)
  {
    vector<string> ans;
    for (int i = 0; i < s.size(); i += k)
    {
      ans.push_back(s.substr(i, k));
    }
    int last = ans.size() - 1;
    while (last >= 0 && ans[last].size() < k)
    {
      ans[last].push_back(fill);
    }
    return ans;
  }
};
