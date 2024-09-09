#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class NestedInteger {
 public:
  bool isInteger() const;

  int getInteger() const;

  const vector<NestedInteger>& getList() const;
};

class NestedIterator {
 private:
  vector<int> cache;
  size_t pos;

 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    cache = getInts(nestedList);
    pos = 0;
  }

  int next() {
    int temp = cache[pos++];
    return temp;
  }

  bool hasNext() { return bool(pos < cache.size()); }

  vector<int> getInts(const vector<NestedInteger>& nestedList) {
    vector<int> ret;
    for (const auto& ni : nestedList) {
      auto temp = getInts(ni);
      ret.insert(ret.end(), temp.begin(), temp.end());
    }
    return ret;
  }
  vector<int> getInts(const NestedInteger& ni) {
    if (ni.isInteger()) {
      return vector<int>{ni.getInteger()};
    }
    return getInts(ni.getList());
  }
};
