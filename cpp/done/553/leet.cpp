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
  string optimalDivision(vector<int>& ns)
  {
    int n = ns.size();
    if (n == 1)
      return to_string(ns[0]);
    if (n == 2)
      return to_string(ns[0]) + "/" + to_string(ns[1]);
    string down = "(" + to_string(ns[1]);
    for (int i = 2; i < n; i++)
    {
      down += "/" + to_string(ns[i]);
    }
    down += ")";
    return to_string(ns[0]) + "/" + down;
  }
};
