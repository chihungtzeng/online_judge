# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if root:
            self.my_flatten(root)

    def my_flatten(self, root):
        left = root.left
        right = root.right
        last = root
        if left:
            root.left = None
            root.right = left
            last = self.my_flatten(left)
        if right:
            last.right = right
            last = self.my_flatten(right)
        return last
