class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        return self.sum_n(root, 0)

    def sum_n(self, root, n):
        n = (n << 3) + (n << 1) + root.val
        res = 0
        if root.left is None and root.right is None:
            return n
        if root.left:
            res += self.sum_n(root.left, n)
        if root.right:
            res += self.sum_n(root.right, n)
        return res
