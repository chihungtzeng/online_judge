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

using ituple = tuple<int, int, int>;

class FreqStack
{
public:
  int pos;
  unordered_map<int, vector<int>> val_pos;
  set<ituple> s;

  FreqStack() : pos(0)
  {
  }

  void push(int val)
  {
    pos++;
    auto it = val_pos.find(val);
    if (it == val_pos.end())
    {
      val_pos[val].push_back(pos);
      s.insert({ 1, pos, val });
    }
    else
    {
      int freq = it->second.size();
      int last_pos = it->second.back();
      s.erase({ freq, last_pos, val });
      s.insert({ freq + 1, pos, val });
      it->second.push_back(pos);
    }
  }

  int pop()
  {
    auto it = s.rbegin();
    int freq = get<0>(*it);
    int last_pos = get<1>(*it);
    int val = get<2>(*it);
    s.erase({ freq, last_pos, val });
    val_pos[val].pop_back();
    if (val_pos[val].empty())
    {
      val_pos.erase(val);
    }
    else
    {
      s.insert({ val_pos[val].size(), val_pos[val].back(), val });
    }
    return val;
  }
};

