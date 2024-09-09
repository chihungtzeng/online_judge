#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
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

struct DisjointSet
{
  vector<int> parents, ranks;
  DisjointSet(int n) : parents(n), ranks(n)
  {
    for (int i = 0; i < n; i++)
    {
      parents[i] = i;
    }
  }
  int find(int u)
  {
    if (parents[u] != u)
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
    else if (ranks[ur] == ranks[vr])
    {
      parents[ur] = vr;
      ranks[vr]++;
    }
    else
    {
      parents[vr] = ur;
    }
  }
};

class Solution
{
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
  {
    unordered_map<string, string> email2name;
    unordered_map<string, int> email2id;
    unordered_map<int, string> id2email;
    for (auto& vec : accounts)
    {
      for (int i = 1; i < vec.size(); i++)
      {
        email2name[vec[i]] = vec[0];
        if (email2id.count(vec[i]) == 0)
        {
          int idx = email2id.size();
          email2id[vec[i]] = idx;
          id2email[idx] = vec[i];
        }
      }
    }
    DisjointSet ds(email2name.size());
    for (auto& vec : accounts)
    {
      for (int i = 1; i < vec.size(); i++)
      {
        int id = email2id[vec[i]];
        for (int j = i + 1; j < vec.size(); j++)
        {
          int id2 = email2id[vec[j]];
          ds.join(id, id2);
        }
      }
    }
    unordered_map<string, vector<string>> merged_acc;
    for (int i = 0; i < email2id.size(); i++)
    {
      string email = id2email[i];
      int root = ds.find(i);
      string root_email = id2email[root];
      merged_acc[root_email].push_back(email);
    }
    vector<vector<string>> res(merged_acc.size());
    int i = 0;
    for (auto& [root_email, emails] : merged_acc)
    {
      res[i].push_back(email2name[root_email]);
      sort(emails.begin(), emails.end());
      for (auto& email : emails)
      {
        res[i].push_back(email);
      }
      i++;
    }
    return res;
  }
};
