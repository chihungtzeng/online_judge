#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

using Seg = std::pair<long long, long long>;
class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    vector<Seg> hs{{A,C}, {E,G}};
    vector<Seg> vs{{B,D}, {F,H}};
    auto total_area = length(hs[0]) * length(vs[0]) + length(hs[1]) * length(vs[1]);
    auto overlap_area = length(overlap(hs[0], hs[1])) * length(overlap(vs[0], vs[1]));
    return total_area - overlap_area;

  }
  Seg overlap(const Seg& seg1, const Seg& seg2)
  {
    std::vector<Seg> segs{seg1, seg2};
    std::sort(segs.begin(), segs.end());
    if (segs[0].second > segs[1].first)
    {
      return Seg{max(segs[0].first, segs[1].first), min(segs[0].second, segs[1].second)};
    }
    return Seg{0, 0};
  }
  long long length(const Seg& seg)
  {
    return seg.second - seg.first;
  }
};
