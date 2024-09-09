class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        max_path_sum, max_path = self.traverse(root)
        return max_path_sum

    def traverse(self, root):
        if root.left and root.right:
            lmps, lmp = self.traverse(root.left)
            rmps, rmp = self.traverse(root.right)
            max_path = max(root.val, max(lmp, rmp) + root.val)
            max_path_sum = max(lmps, rmps, lmp + rmp + root.val, max_path)
        elif root.left:
            lmps, lmp = self.traverse(root.left)
            max_path = max(lmp + root.val, root.val)
            max_path_sum = max(lmps, max_path)
        elif root.right:
            rmps, rmp = self.traverse(root.right)
            max_path = max(rmp + root.val, root.val)
            max_path_sum = max(rmps, max_path)
        else:
            max_path = root.val
            max_path_sum = root.val

        return max_path_sum, max_path

