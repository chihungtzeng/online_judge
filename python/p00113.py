# Definition for a binary tree node.
import unittest
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        sol = []
        cur_path = []
        if root:
            self.pathSum2(root, sum, cur_path, sol)
        return sol

    def pathSum2(self, root, remaining, cur_path, sol):
        cur_path.append(root.val)
        cur_remaining = remaining - root.val
        if root.left is None and root.right is None and cur_remaining == 0:
            sol.append([_ for _ in cur_path])
        if root.left:
            self.pathSum2(root.left, cur_remaining, cur_path, sol)
        if root.right:
            self.pathSum2(root.right, cur_remaining, cur_path, sol)
        cur_path.pop()

class SolTest(unittest.TestCase):
    def test_1(self):
        node = TreeNode(5)
        sol = Solution()
        res = sol.pathSum(node, 5)
        print(res)
    def test_2(self):
        sol = Solution()
        res = sol.pathSum(None, 5)
        print(res)



unittest.main()

