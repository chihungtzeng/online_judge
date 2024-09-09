class SegmentTreeNode {
 public:
  int low, hi, sum;
  SegmentTreeNode *left, *right;
  SegmentTreeNode(int low, int hi)
      : low(low), hi(hi), sum(0), left(nullptr), right(nullptr){};
};

SegmentTreeNode* buildTree(int from, int to, vector<int>& nums) {
  if (from > to) return nullptr;
  SegmentTreeNode* root = new SegmentTreeNode(from, to);
  if (from == to) {
    root->sum = nums[from];
    return root;
  }
  int mid = from + (to - from) / 2;
  root->left = buildTree(from, mid, nums);
  root->right = buildTree(mid + 1, to, nums);
  root->sum =
      (root->left ? root->left->sum : 0) + (root->right ? root->right->sum : 0);
  return root;
}

void updateTree(SegmentTreeNode* root, int index, int val) {
  if (root->low == index && root->hi == index) {
    root->sum = val;
    return;
  }
  int mid = root->low + (root->hi - root->low) / 2, left = 0, right = 0;
  if (index <= mid)
    updateTree(root->left, index, val);
  else
    updateTree(root->right, index, val);
  root->sum =
      (root->left ? root->left->sum : 0) + (root->right ? root->right->sum : 0);
  return;
}

int rsum(SegmentTreeNode* root, int from, int to) {
  if (root->low == from && root->hi == to) return root->sum;
  int mid = root->low + (root->hi - root->low) / 2;
  if (to <= mid) return rsum(root->left, from, to);
  if (mid < from) return rsum(root->right, from, to);
  return rsum(root->left, from, mid) + rsum(root->right, mid + 1, to);
}

class NumArray {
  SegmentTreeNode* root;

 public:
  NumArray(vector<int>& nums) { root = buildTree(0, nums.size() - 1, nums); }

  void update(int i, int val) { updateTree(root, i, val); }

  int sumRange(int i, int j) { return rsum(root, i, j); }
};
