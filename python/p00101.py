# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        return self.is_identical(root.left, root.right)

    def is_identical(self, left, right):
        if left is None and right is None:
            return True
        if left is None and right:
            return False
        if left and right is None:
            return False
        if left.val != right.val:
            return False
        if not self.is_identical(left.left, right.right):
            return False
        return self.is_identical(left.right, right.left)
