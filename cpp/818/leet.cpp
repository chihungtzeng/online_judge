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

struct CarState
{
  int speed, pos;
  int steps, dir;

  CarState(int speed, int pos, int steps, int dir) : speed(speed), pos(pos), steps(steps), dir(dir)
  {
  }
  bool operator<(const CarState& other) const
  {
    return steps < other.steps;
  }
  bool operator>(const CarState& other) const
  {
    return steps > other.steps;
  }
};

class Solution
{
public:
  int racecar(int target)
  {
    priority_queue<CarState, vector<CarState>, greater<>> pq;

    map<int, int> dists;
    CarState cs(1, 0, 0, 1);
    pq.push(cs);

    while (!pq.empty())
    {
      auto s = pq.top();
      pq.pop();

      vector<CarState> next_states{ CarState(s.speed * 2, s.speed + s.pos, s.steps + 1, s.dir),
                                    CarState(-s.dir * 2, s.pos -1 , s.steps + 2, -s.dir) };

      for (auto& ns : next_states)
      {
        if (target == ns.pos)
          return ns.steps;

        if (dists.count(ns.pos) == 0 && abs(ns.speed) <= 10000) {
          dists[ns.pos] = ns.steps;
          pq.push(ns);
        }
      }
    }
    return 0;
  }
};
