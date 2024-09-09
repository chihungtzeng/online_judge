# Definition for a binary tree node.
import unittest
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.cur = root
        self.stack = []

    def next(self):
        """
        @return the next smallest number
        :rtype: int
        """
        self.go_next()
        self.cur = self.stack.pop()
        ret = self.cur.val
        self.cur = self.cur.right
        return ret

    def hasNext(self):
        """
        @return whether we have a next smallest number
        :rtype: bool
        """
        return bool(self.cur) or bool(self.stack)

    def go_next(self):
        while self.cur:
            self.stack.append(self.cur)
            self.cur = self.cur.left
        
class SolTest(unittest.TestCase):
    def test_1(self):
        node7 = TreeNode(7)
        node3 = TreeNode(3)
        node15 = TreeNode(15)
        node9 = TreeNode(9)
        node20 = TreeNode(20)
        node7.left = node3
        node7.right = node15
        node15.left = node9
        node15.right = node20
        iterator = BSTIterator(node7);
        self.assertEqual(iterator.next(), 3)
        self.assertEqual(iterator.next(), 7)
        self.assertEqual(iterator.hasNext(), True)
        self.assertEqual(iterator.next(), 9)
        self.assertEqual(iterator.hasNext(), True)
        self.assertEqual(iterator.next(), 15)
        self.assertEqual(iterator.hasNext(), True)
        self.assertEqual(iterator.next(), 20)
        self.assertEqual(iterator.hasNext(), False)

unittest.main()
