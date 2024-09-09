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

class MyCircularQueue {
 public:
  int front_, rear_, cap_;
  vector<int> q_;
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) : front_(-1), rear_(-1), cap_(k), q_(k) {}

  /** Insert an element into the circular queue. Return true if the operation is
   * successful. */
  bool enQueue(int value) {
    if (isEmpty()) {
      q_[++rear_] = value;
      front_ = rear_;
    } else if (isFull()) {
      return false;
    } else {
      int idx = (rear_ + 1) % cap_;
      q_[idx] = value;
      rear_ = idx;
    }
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is
   * successful. */
  bool deQueue() {
    if (isEmpty()) return false;
    if (front_ == rear_) {
      front_ = -1;
      rear_ = -1;
    } else {
      front_ = (front_ + 1) % cap_;
    }
    return true;
  }

  /** Get the front item from the queue. */
  int Front() { return isEmpty() ? -1 : q_[front_]; }

  /** Get the last item from the queue. */
  int Rear() { return isEmpty() ? -1 : q_[rear_]; }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() { return front_ < 0; }

  /** Checks whether the circular queue is full or not. */
  bool isFull() { return front_ >= 0 && (front_ == (rear_ + 1) % cap_); }
};

