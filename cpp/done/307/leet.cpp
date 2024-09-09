#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#define DEBUG 1
using namespace std;

class BIT
{
public:
  vector<int> vals;
  BIT(int n) : vals(n)
  {
  }
  void update(int i, int val)
  {
    for (; i < vals.size(); i += i & (-i))
      vals[i] += val;
  }
  int rsum(int i)
  {
    int sum = 0;
    for (; i > 0; i -= i & (-i))
    {
      sum += vals[i];
    }
    return sum;
  }
};

class NumArray
{
public:
  vector<int> org;
  BIT bitree;
  NumArray(vector<int>& A) : org(A.size()), bitree(A.size() + 1)
  {
    for (int i = 0; i < A.size(); i++)
    {
      bitree.update(i + 1, A[i]);
      org[i] = A[i];
    }
  }

  void update(int i, int val)
  {
    int diff = val - org[i];
    org[i] = val;
    bitree.update(i + 1, diff);
  }

  int sumRange(int i, int j)
  {
    return bitree.rsum(j + 1) - bitree.rsum(i);
  }
};

