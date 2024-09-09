class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        return self.pt(root, ret)

    def pt(self, root, ret):
        if not root:
            return ret
        self.pt(root.left, ret)
        self.pt(root.right, ret)
        ret.append(root.val)
        return ret

