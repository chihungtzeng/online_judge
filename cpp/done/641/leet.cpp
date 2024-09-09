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

class MyCircularDeque {
 public:
  int front_, rear_, cap_;
  vector<int> q_;
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k): front_(-1), rear_(-1), cap_(k), q_(k) {}

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value) {
    if (isEmpty()) {
      q_[0] = value;
      rear_ = 0;
      front_ = 0;
    } else if (isFull()){
      return false;
    } else {
      front_ = (front_ - 1 + cap_) % cap_;
      q_[front_] = value;
    }
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value) {
    if (isEmpty()) {
      q_[0] = value;
      rear_ = 0;
      front_ = 0;
    } else if (isFull()){
      return false;
    } else {
      rear_ = (rear_ + 1) % cap_;
      q_[rear_] = value;
    }
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront() {
    if (isEmpty()) return false;
    else if (front_ == rear_) {
      front_ = -1;
      rear_ = -1;
    } else {
      front_ = (front_ + 1) % cap_;
    }
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast() {
    if (isEmpty()) return false;
    else if (front_ == rear_) {
      front_ = -1;
      rear_ = -1;
    } else {
      rear_ = (rear_ - 1 + cap_) % cap_;
    }
    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    if (isEmpty()) return -1;
    return q_[front_];
  }

  /** Get the last item from the deque. */
  int getRear() {
    if (isEmpty()) return -1;
    return q_[rear_];
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() {
    return bool(front_ < 0);
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull() {
    return (front_ >=0 && front_ == (rear_ + 1) % cap_);
  }
};

