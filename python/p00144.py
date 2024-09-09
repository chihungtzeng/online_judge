# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        return self.pt(root, ret)

    def pt(self, root, ret):
        if not root:
            return ret
        ret.append(root.val)
        self.pt(root.left, ret)
        self.pt(root.right, ret)
        return ret
