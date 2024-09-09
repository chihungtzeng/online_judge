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

struct Node {
  vector<string> nbrs;
  vector<double> weights;
  double pd;
};

unordered_map<string, Node> g_adj_list;
unordered_set<string> g_visited;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    build_graph(equations, values);
    vector<double> qret;
    qret.reserve(queries.size());
    for (auto& query : queries) {
      auto src = query[0];
      auto dest = query[1];
      if (g_adj_list.count(src) == 0 || g_adj_list.count(dest) == 0) {
        qret.push_back(-1.0);
        continue;
      }
      if (src == dest) {
        qret.push_back(1.0);
        continue;
      }
      qret.push_back(bfs(src, dest));
    }
    return qret;
  }
  void build_graph(vector<vector<string>>& equations, vector<double>& values) {
    g_adj_list.clear();
    for (size_t i = 0; i < values.size(); i++) {
      auto eq = equations[i];
      g_adj_list[eq[0]].nbrs.push_back(eq[1]);
      g_adj_list[eq[0]].weights.push_back(values[i]);
      g_adj_list[eq[1]].nbrs.push_back(eq[0]);
      g_adj_list[eq[1]].weights.push_back(1 / values[i]);
    }
  }
  double bfs(string& src, string& dest) {
    g_visited.clear();
    g_adj_list[src].pd = 1.0;
    deque<string> q;
    q.push_back(src);
    g_visited.insert(src);
    while(!q.empty()){
      auto cur_name = q.front();
      q.pop_front();
      for(size_t i=0; i<g_adj_list[cur_name].nbrs.size(); i++){
        auto nbr_name = g_adj_list[cur_name].nbrs[i];
        if (g_visited.count(nbr_name) == 0)
        {
          q.push_back(nbr_name);
          g_adj_list[nbr_name].pd = g_adj_list[cur_name].weights[i] * g_adj_list[cur_name].pd;
          g_visited.insert(nbr_name);
          if (nbr_name == dest) {
            return g_adj_list[nbr_name].pd;
          }
        }
      }
    }
    return -1.0;
  }
};

