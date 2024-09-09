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
    }
    string ans;
    for (auto src : froms["JFK"])
    {
      string can = "JFK,";
      vector<bool> visited(tickets.size(), false);
      dfs(tickets, src, nbrs, can, ans, visited, 0);
    }
    return post_process(ans);
  }
  void dfs(const vector<vector<string>>& tickets, const int cur, const vector<vector<int>>& nbrs, string& can,
           string& ans, vector<bool>& visited, int nvisit)
  {
    visited[cur] = true;
    nvisit++;
    can += tickets[cur][1] + ',';
    if (nvisit == tickets.size())
    {
      if (can.size() > ans.size() || (can < ans))
      {
        ans = can;
      }
    }
    else
    {
      for (auto nbr : nbrs[cur])
      {
        if (!visited[nbr])
        {
          dfs(tickets, nbr, nbrs, can, ans, visited, nvisit);
        }
      }
    }

    visited[cur] = false;
    for (int i = 0; i < 4; i++)
    {
      can.pop_back();
    }
    return;
  }
  vector<string> post_process(string& s)
  {
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
