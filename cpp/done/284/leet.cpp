#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const vector<int> &nums);
  Iterator(const Iterator &iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
  private:
    std::optional<int> val;
public:
  PeekingIterator(const vector<int> &nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.
    val = std::nullopt;
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (val) {
      return *val;
    }
    if (!hasNext()){
      return 0;
    }
    val = next();
    return *val;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (val) {
      auto temp = *val;
      val = std::nullopt;
      return temp;
    }
    return static_cast<Iterator *>(this)->next();
  }

  bool hasNext() const {
    if (val) {
      return true;
    }
    return static_cast<const Iterator *>(this)->hasNext();
  }
};
