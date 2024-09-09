#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using irpair = pair<int, double>;
class Solution
{
public:
  vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals, vector<vector<string>>& queries)
  {
    unordered_map<string, int> var_id;
    for (auto& eq : eqs)
    {
      for (auto& var : eq)
      {
        if (var_id.count(var) == 0)
        {
          var_id[var] = var_id.size();
        }
      }
    }
    vector<vector<irpair>> nbrs(var_id.size());
    for (int i = 0; i < eqs.size(); i++)
    {
      auto& eq = eqs[i];
      int v0 = var_id[eq[0]];
      int v1 = var_id[eq[1]];
      nbrs[v0].push_back({ v1, vals[i] });
      nbrs[v1].push_back({ v0, 1.0 / vals[i] });
    }
    vector<double> res(queries.size());
    for (int i = 0; i < queries.size(); i++)
    {
      if (var_id.count(queries[i][0]) == 0 || var_id.count(queries[i][1]) == 0)
      {
        res[i] = -1;
      }
      else
      {
        vector<bool> visited(var_id.size(), false);
        double qres = 0;
        int v0 = var_id[queries[i][0]];
        int v1 = var_id[queries[i][1]];
        auto found = dfs(v0, v1, nbrs, visited, 1.0, &qres);
        if (found)
        {
          res[i] = qres;
        }
        else
        {
          res[i] = -1;
        }
      }
    }
    return res;
  }
  bool dfs(int src, int dst, vector<vector<irpair>>& nbrs, vector<bool>& visited, double cur_val, double* qres)
  {
    if (src == dst)
    {
      *qres = cur_val;
      return true;
    }
    visited[src] = true;
    for (auto& [nbr, val] : nbrs[src])
    {
      bool found = false;
      if (!visited[nbr])
      {
        found = dfs(nbr, dst, nbrs, visited, cur_val * val, qres);
      }
      if (found)
        return true;
    }
    return false;
  }
};

