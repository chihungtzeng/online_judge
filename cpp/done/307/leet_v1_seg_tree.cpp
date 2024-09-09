#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#define DEBUG 1
using namespace std;

class SegTree {
 public:
  int from, to, val;
  SegTree* left;
  SegTree* right;
  SegTree(int i, int j)
      : from(i), to(j), val(0), left(nullptr), right(nullptr) {}
  int sumRange(int i, int j) {
    if ((from == i) && (to == j)) {
      return val;
    }
    int mid = from + (to - from) / 2;
    if (j <= mid) {
      return left->sumRange(i, j);
    }
    if (i > mid) {
      return right->sumRange(i, j);
    }
    return left->sumRange(i, mid) + right->sumRange(mid+1, j);
  }
  void update(int i, int v) {
    if ((from == i) && (to == i)) {
      val = v;
      return;
    }
    int mid = from + (to - from) / 2;
    if (i <= mid) {
      left->update(i, v);
    }
    if (i > mid) {
      right->update(i, v);
    }
    val = (left? left->val: 0) + (right? right->val : 0);
  }
  ~SegTree() {
    if (left) {
      delete left;
      left = nullptr;
    }
    if (right) {
      delete right;
      right = nullptr;
    }
  }
};

class NumArray {
 public:
  SegTree* seg_tree;
#if DEBUG
  std::vector<int> nums_;
#endif
  NumArray(vector<int>& nums): seg_tree(nullptr) {
    if (nums.size() > 0) {
      seg_tree = buildTree(0, nums.size() - 1, nums);
    }
#if DEBUG
    nums_ = nums;
#endif
  }

  void update(int i, int val) {
    seg_tree->update(i, val);
#if DEBUG
    nums_[i] = val;
#endif
  }

  int sumRange(int i, int j) { return seg_tree->sumRange(i, j); }
  SegTree* buildTree(int i, int j, vector<int>& nums) {
    SegTree* root = new SegTree(i, j);
    int mid = root->from + (root->to - root->from) / 2;
    if ((mid == root->to) && (mid == root->from)) {
      root->val = nums[mid];
      return root;
    }
    root->left = buildTree(i, mid, nums);
    root->right = buildTree(mid + 1, j, nums);
    root->val = (root->left? root->left->val: 0) +
      (root->right? root->right->val: 0);
//    LOG(INFO) << "[" << root->from << ", " << root->to << "]: " << root->val;
    return root;
  }
  ~NumArray() {
    if (seg_tree) {
      delete seg_tree;
      seg_tree = nullptr;
    }
  }
};

