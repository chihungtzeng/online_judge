#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using itpair = pair<vector<int>::const_iterator, vector<int>::const_iterator>;
class ZigzagIterator
{
public:
  vector<itpair> its_;
  int idx_;
  ZigzagIterator(vector<int>& v1, vector<int>& v2) : its_(2), idx_(0)
  {
    its_[0] = { v1.begin(), v1.end() };
    its_[1] = { v2.begin(), v2.end() };
  }

  int next()
  {
    if (reach_end(idx_))
    {
      idx_ = 1 - idx_;
    }
    auto ret = *(its_[idx_].first);
    its_[idx_].first += 1;
    idx_ = 1 - idx_;
    return ret;
  }

  bool hasNext()
  {
    return !bool(reach_end(0) && reach_end(1));
  }
  bool reach_end(int idx)
  {
    return bool(its_[idx].first == its_[idx].second);
  }
};

