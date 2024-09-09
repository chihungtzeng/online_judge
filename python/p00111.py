# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        left_depth = self.minDepth(root.left) if root.left else float("inf")
        right_depth = self.minDepth(root.right) if root.right else float("inf")
        return 1 + min(left_depth, right_depth)
