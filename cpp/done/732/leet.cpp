#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cassert>
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

class SegTreeNode {
 public:
  int low_, high_, num_overlap_, booked_;
  SegTreeNode *left_, *right_;
  SegTreeNode(int l, int r)
      : low_(l),
        high_(r),
        num_overlap_(0),
        booked_(0),
        left_(nullptr),
        right_(nullptr) {
    // LOG(INFO) << "new tree node [" << low_ << ", " << high_ << "]";
  }
  ~SegTreeNode() {
    if (left_) delete left_;
    if (right_) delete right_;
  }
  void insert(int start, int end) {
    // LOG(INFO) << "insert ( " << start << ", " << end << ") at [" << low_ <<
    // ", " << high_ << "]";
    if (start > end) {
      //      LOG(INFO) << "start: " << start << " end: " << end << ", do
      //      nothing";
      return;
    }
    if (start == low_ && end == high_) {
      // LOG(INFO) << "Exact insert at (" << start << ", " << end << ")";
      booked_++;
      int nleft = (left_) ? left_->num_overlap_ : 0;
      int nright = (right_) ? right_->num_overlap_ : 0;
      num_overlap_ = booked_ + max(nleft, nright);
      return;
    }
    int mid = low_ + (high_ - low_) / 2;
    if (!left_) left_ = new SegTreeNode(low_, mid);
    if (!right_) right_ = new SegTreeNode(mid + 1, high_);
    if (end <= mid) {
      left_->insert(start, end);
    } else if (start > mid) {
      right_->insert(start, end);
    } else {
      left_->insert(start, mid);
      right_->insert(mid + 1, end);
    }

    int nleft = (left_) ? left_->num_overlap_ : 0;
    int nright = (right_) ? right_->num_overlap_ : 0;
    num_overlap_ = booked_ + max(nleft, nright);
  }
};

class MyCalendarThree {
 public:
  SegTreeNode *seg_tree_;
  MyCalendarThree() : seg_tree_(new SegTreeNode(0, 1000000000)) {}
  ~MyCalendarThree() { delete seg_tree_; }

  int book(int start, int end) {
    seg_tree_->insert(start, end - 1);
    return seg_tree_->num_overlap_;
  }
};

