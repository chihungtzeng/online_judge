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

class BrowserHistory {
 public:
  vector<string> urls;
  int cur;
  BrowserHistory(string homepage) {
    urls.push_back(homepage);
    cur = 0;
  }

  void visit(string url) {
    if (cur != urls.size() - 1) {
      urls.resize(cur + 1);
    }
    urls.push_back(url);
    cur++;
  }

  string back(int steps) {
    if (cur - steps < 0)
      cur = 0;
    else
      cur = cur - steps;
    return urls[cur];
  }

  string forward(int steps) {
    if (cur + steps >= urls.size())
      cur = urls.size() - 1;
    else
      cur += steps;
    return urls[cur];
  }
};
