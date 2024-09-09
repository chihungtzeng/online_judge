#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <deque>
using namespace std;

class MyStack {
public:
  /** Initialize your data structure here. */
  std::deque<int> q;
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    q.push_back(x);
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    auto ret = q.back();

    q.pop_back();
    return ret;
  }

  /** Get the top element. */
  int top() {
    return q.back();
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return q.empty();
  }
};
