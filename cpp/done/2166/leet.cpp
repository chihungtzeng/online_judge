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

class Bitset
{
private:
  const int nbits_;
  int nones_;
  int is_flip_;
  string segs_;

public:
  Bitset(int size) : nbits_(size), nones_(0), is_flip_(0), segs_(size, '0')
  {
  }

  void set_bit(const int idx, const int val)
  {
    if (segs_[idx] == val)
      return;

    segs_[idx] = val;
    if (val == '0')
    {
      --nones_;
    }
    else
    {
      ++nones_;
    }
  }

  void fix(const int idx)
  {
    set_bit(idx, 1 - is_flip_ + '0');
  }

  void unfix(const int idx)
  {
    set_bit(idx, is_flip_ + '0');
  }

  void flip()
  {
    is_flip_ = 1 - is_flip_;
  }

  bool all()
  {
    if (is_flip_)
      return nones_ == 0;
    return nones_ == nbits_;
  }

  bool one()
  {
    if (!is_flip_)
    {
      return nones_ > 0;
    }
    else
    {
      return nbits_ - nones_ > 0;
    }
  }

  int count()
  {
    if (is_flip_)
      return nbits_ - nones_;
    return nones_;
  }

  string toString()
  {
    string s = segs_;
    if (is_flip_)
    {
      for (int i = s.size() - 1; i >= 0; i--)
      {
        s[i] = '0' + '1' - s[i];
      }
    }

    return s;
  }
};

