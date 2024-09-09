#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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

class Solution {
 public:
  vector<int> closestRoom(vector<vector<int>>& rooms,
                          vector<vector<int>>& queries) {
    for (int i = rooms.size() - 1; i >= 0; i--) {
      rooms[i].push_back('R');
      rooms[i].push_back(i);
    }
    for (int i = queries.size() - 1; i >= 0; i--) {
      rooms.emplace_back(vector<int>{queries[i][0], queries[i][1], 'Q', i});
    }
    auto cmp = [](const auto& a, const auto& b) {
      if (a[1] != b[1]) {
        return a[1] < b[1];
      }
      return a[2] < b[2];
    };
    sort(rooms.begin(), rooms.end(), cmp);
#if 0    
    for (auto& r : rooms) {
      LOG(INFO) << r;
    }
#endif    
    vector<int> ans(queries.size(), -1);
    set<int> ids, neg_ids;

    for (int i = rooms.size() - 1; i >= 0; i--) {
      if (rooms[i][2] == 'R') {
        ids.insert(rooms[i][0]);
        neg_ids.insert(-rooms[i][0]);
      } else {
        // it is query
        int idx = rooms[i][3];
        int qid = rooms[i][0];
        ans[idx] = find_best_id(idx, qid, ids, neg_ids);
      }
    }
    return ans;
  }
  int find_best_id(int idx, int qid, set<int>& ids, set<int>& neg_ids) {
    auto it = ids.lower_bound(qid);
    auto neg_it = neg_ids.lower_bound(-qid);

//    LOG(INFO) << "idx: " << idx << ", qid: " << qid << ", neg_ids: " << neg_ids;

    if (it == ids.end() && neg_it != neg_ids.end()) {
//      LOG(INFO) << "only *neg_it: " << *neg_it;
      return -(*neg_it);
    } else if (it != ids.end() && neg_it == neg_ids.end()) {
//      LOG(INFO) << "only *it: " << *it;
      return *it;
    } else if (it != ids.end() && neg_it != neg_ids.end()) {
//      LOG(INFO) << "*it: " << *it << ", *neg_it: " << *neg_it;
      int diff1 = abs(*it - qid);
      int diff2 = abs(-(*neg_it) - qid);
      if (diff1 == diff2) {
        return min(*it, -(*neg_it));
      } else if (diff1 < diff2) {
        return *it;
      } else {
        return -(*neg_it);
      }
    } else {
      return -1;
    }
  }
};
