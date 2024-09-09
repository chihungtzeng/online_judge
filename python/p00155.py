import unittest
class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.mstack = []
        self.stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.append(x)
        if not self.mstack or self.mstack[-1] >= x:
            self.mstack.append(x)

    def pop(self):
        """
        :rtype: None
        """
        x = self.stack.pop()
        if x <= self.mstack[-1]:
            self.mstack.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.mstack[-1]


class SolTest(unittest.TestCase):
    def test_1(self):
        minStack = MinStack()
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        self.assertEqual(-3, minStack.getMin())
        minStack.pop();
        self.assertEqual(0, minStack.top())
        self.assertEqual(-2, minStack.getMin())

unittest.main()
