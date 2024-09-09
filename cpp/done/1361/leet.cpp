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


struct DisjointSet {
  public:
    vector<int> parents, ranks;
    DisjointSet(int n): parents(n), ranks(n){
      for(int i=0; i<n; i++) parents[i] = i;
    }
    int find(int u){
      if (u != parents[u]) parents[u] = find(parents[u]);
      return parents[u];
    }
    void join(int u, int v){
      int ur = find(u), vr = find(v);
      if (ur == vr) return;
      if (ranks[ur] < ranks[vr]) parents[ur] = vr;
      else if (ranks[ur] == ranks[vr]){
        parents[ur] = vr;
        ranks[vr]++;
      } else {
        parents[vr] = ur;
      }
    }
};

using ipair = pair<int, int>;
class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    set<ipair> edges;
    DisjointSet ds(n);
    for (int i = 0; i < n; i++) {
      if (leftChild[i] >= 0) {
        int j = leftChild[i];
        if (ds.find(i) == ds.find(j)) return false;
        ipair edge{i, j};
        edges.insert(edge);
        ds.join(i, j);
        ipair redge{j, i};
        if (edges.find(redge) != edges.end()) {
          return false;
        }
      }
      if (rightChild[i] >= 0) {
        int j = rightChild[i];
        if (ds.find(i) == ds.find(j)) return false;
        ipair edge{i, j};
        edges.insert(edge);
        ds.join(i, j);
        ipair redge{j, i};
        if (edges.find(redge) != edges.end()) {
          return false;
        }
      }
    }
    // LOG(INFO) << edges;
    return (edges.size() == n - 1);
  }
};
