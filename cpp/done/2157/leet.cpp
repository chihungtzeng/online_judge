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

class DisjointSet
{
private:
  vector<int> parents, ranks;

public:
  DisjointSet(int n) : parents(n), ranks(n, 0)
  {
    for (int i = 0; i < n; i++)
      parents[i] = i;
  }

  int find(int u)
  {
    if (u != parents[u])
    {
      parents[u] = find(parents[u]);
    }
    return parents[u];
  }

  void join(int u, int v)
  {
    int ur = find(u), vr = find(v);
    if (ur == vr)
      return;

    if (ranks[ur] < ranks[vr])
    {
      parents[ur] = vr;
    }
    else if (ranks[ur] > ranks[vr])
    {
      parents[vr] = ur;
    }
    else
    {
      parents[ur] = vr;
      ranks[vr]++;
    }
  }
  vector<int> groups_info()
  {
    unordered_map<int, int> gsize;
    for (int i = parents.size() - 1; i >= 0; i--)
    {
#if DEBUG
      LOG(INFO) << i << ", parent: " << find(i);
#endif
      gsize[find(i)]++;
    }
    int res = 0;
    for (auto& [root, sz] : gsize)
    {
      res = max(res, sz);
    }
    return vector<int>{ static_cast<int>(gsize.size()), res };
  }
  void groups_info(vector<string>& words)
  {
    for (int i = parents.size() - 1; i >= 0; i--)
    {
      int pi = find(i);
      string str = words[i] + "(" + to_string(i) + ") -> " + words[pi] + "(" + to_string(pi) + ")";

#if DEBUG
      LOG(INFO) << str;
#endif
    }
  }
};

class Solution
{
public:
  vector<int> groupStrings(vector<string>& words)
  {
    const int n = words.size();
    unordered_map<int, int> w2idx;
    vector<int> wvs;
    wvs.reserve(n);
    for (int i = 0; i < n; i++)
    {
      int wv = to_val(words[i]);
      w2idx[wv] = i;
      wvs.push_back(wv);
#if DEBUG
      LOG(INFO) << words[i] << " : " << wv;
#endif
    }
    DisjointSet ds(n);
    for (int idx = 0; idx < n; idx++)
    {
      auto wv = wvs[idx];
      for (int j = 0; j < 26; j++)
      {
        auto other = flip_bit(wv, j);
        auto it = w2idx.find(other);
        if (it == w2idx.end())
          continue;
        ds.join(idx, it->second);

#if DEBUG
        LOG(INFO) << "join " << idx << " and " << it->second;
#endif
      }
      for (int j = 0; j < 26; j++)
      {
        if (bit_of(wv, j) == 0)
          continue;
        for (int k = 0; k < 26; k++)
        {
          if (k != j && bit_of(wv, k) == 1)
            continue;
          auto wv_prime = replace_bit(wv, j, k);
          auto it = w2idx.find(wv_prime);
          if (it != w2idx.end())
          {
            ds.join(idx, it->second);
#if DEBUG
            LOG(INFO) << "join " << idx << " and " << it->second;
#endif
          }
        }
      }
    }
    // ds.groups_info(words);
    return ds.groups_info();
  }

  int to_val(const string& w)
  {
    int v = 0;
    for (auto ch : w)
    {
      v |= (1 << (ch - 'a'));
    }
    return v;
  }
  int flip_bit(int v, int pos)
  {
    return v ^ (1 << pos);
  }
  int replace_bit(int v, int i, int j)
  {
    v ^= 1 << i;
    return v ^ (1 << j);
  }
  int bit_of(int v, int i)
  {
    return (v >> i) & 1;
  }
};
