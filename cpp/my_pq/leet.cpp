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

class PQ
{
private:
  vector<int> vals_;
  void build()
  {
    for (int i = vals_.size() >> 1; i >= 0; i--)
    {
      heapify(i);
    }
  }
  void heapify(int i)
  {
    int smallest = i;
    int lc = left(i), rc = right(i);
    int sz = vals_.size();
    if (lc < sz && vals_[lc] < vals_[smallest])
      smallest = lc;
    if (rc < sz && vals_[rc] < vals_[smallest])
      smallest = rc;
    if (smallest != i)
    {
      swap(vals_[smallest], vals_[i]);
      heapify(smallest);
    }
  }

  int parent(int i)
  {
    return (i - 1) >> 1;
  }
  int left(int i)
  {
    return (i << 1) + 1;
  }
  int right(int i)
  {
    return (i << 1) + 2;
  }

public:
  PQ(vector<int> vals) : vals_(vals)
  {
    build();
  }
  bool empty()
  {
    return vals_.empty();
  }
  int top()
  {
    return vals_[0];
  }
  void push(int val)
  {
    vals_.push_back(val);
    int i = vals_.size() - 1;
    int pi = parent(i);
    while (i > 0 && vals_[i] < vals_[pi])
    {
      vals_[i] = vals_[pi];
      vals_[pi] = val;
      i = pi;
      pi = parent(i);
    }
  }
  void pop()
  {
    if (empty())
      return;
    vals_[0] = vals_.back();
    vals_.pop_back();
    heapify(0);
  }
};
