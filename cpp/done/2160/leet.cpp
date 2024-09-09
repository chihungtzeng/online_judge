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
  int minimumSum(int num)
  {
    string s = to_string(num);
    vector<string> vals(2, "0");
    sort(s.begin(), s.end());
    for (int i = 3; i >= 0; i--)
    {
      vals[1] = s[i] + vals[1];
      if (stoi(vals[0]) < stoi(vals[1]))
        swap(vals[0], vals[1]);
    }
    return (stoi(vals[0]) + stoi(vals[1])) / 10;
  }
};
