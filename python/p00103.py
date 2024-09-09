# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
import unittest

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        lorder = {}
        if root:
            self.traverse(root, lorder, 0)
        level = 0
        ret = []
        while level in lorder:
            if level % 2 == 0:
                ret.append(lorder[level])
            else:
                ret.append(list(reversed(lorder[level])))
            level += 1
        return ret

    def traverse(self, root, lorder, level):
        if level in lorder:
            lorder[level].append(root.val)
        else:
            lorder[level] = [root.val]

        if root.left:
            self.traverse(root.left, lorder, level+1)
        if root.right:
            self.traverse(root.right, lorder, level+1)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.zigzagLevelOrder(None), [])

    def test_2(self):
        sol = Solution()
        node = TreeNode(3)
        self.assertEqual(sol.zigzagLevelOrder(node), [[3]])

    def test_3(self):
        sol = Solution()
        nodes = [TreeNode(_) for _ in range(21)]
        nodes[3].left = nodes[9]
        nodes[3].right = nodes[20]
        nodes[20].left = nodes[15]
        nodes[20].right = nodes[7]
        self.assertEqual(sol.zigzagLevelOrder(nodes[3]), [[3], [20,9], [15, 7]])

unittest.main()
