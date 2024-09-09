import unittest
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        from collections import deque
        if not root:
            return None
        ret = []
        q = deque()
        q.append((root, 1))
        next_node = None
        while q:
            node, level = q.popleft()
            if node.left:
                q.append((node.left, level + 1))
            if node.right:
                q.append((node.right, level + 1))
            if q:
                next_node, next_level = q[0]
                if level != next_level:
                    ret.append(node.val)
        if node != root or not ret:
            ret.append(node.val)
        return ret
        
class SolTest(unittest.TestCase):
    def test_1(self):
        nodes = []
        for v in [1, 2, 3, 4]:
            nodes.append(TreeNode(v))
        nodes[0].left = nodes[1]
        nodes[0].right = nodes[2]
        nodes[2].left = nodes[3]
        sol = Solution()
        self.assertEqual(sol.rightSideView(nodes[0]), [1, 3, 4])
        print(sol.rightSideView(nodes[0]))

    def test_2(self):
        node = TreeNode(1)
        sol = Solution()
        self.assertEqual(sol.rightSideView(node), [1])


unittest.main()        
        
