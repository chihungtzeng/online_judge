#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<string> findItinerary(vector<vector<string>>& tickets)
  {
    unordered_map<string, vector<int>> froms;
    for (int i = 0; i < tickets.size(); i++)
    {
      froms[tickets[i][0]].push_back(i);
    }
    vector<vector<int>> nbrs(tickets.size());
    for (int i = 0; i < tickets.size(); i++)
    {
      nbrs[i] = froms[tickets[i][1]];
      LOG(INFO) << "nbrs of " << i << " : " << nbrs[i];
    }
    string ans;
    for (auto src : froms["JFK"])
    {
      LOG(INFO) << "traverse from " << src;
      string can = "JFK,";
      vector<int8_t> visited(tickets.size(), 0);
      dfs(tickets, src, nbrs, can, ans, visited, 0);
      LOG(INFO) << "can: " << can;
    }
    return post_process(ans);
  }
  void dfs(vector<vector<string>>& tickets, int cur, vector<vector<int>>& nbrs, string& can, string& ans,
           vector<int8_t>& visited, int nvisit)
  {
    visited[cur] = 1;
    nvisit++;
    can += tickets[cur][1] + ',';
    for (auto nbr : nbrs[cur])
    {
      if (visited[nbr] == 0)
      {
        dfs(tickets, nbr, nbrs, can, ans, visited, nvisit);
      }
    }
    visited[cur] = 2;

    if (cur == 32)
    {
      LOG(INFO) << "cur is 32";
      LOG(INFO) << "can: " << can;

    }
    if (nvisit == tickets.size())
    {
      LOG(INFO) << "reach base case, cur=" << cur;
      if (can.size() > ans.size() || (can < ans))
      {
        ans = can;
      }
    }
  }
  vector<string> post_process(string& s)
  {
    if (s.empty())
      return {};
    s.pop_back();
    string token;
    vector<string> res;
    istringstream iss(s);
    while (getline(iss, token, ','))
    {
      res.push_back(token);
    }
    return res;
  }
};
