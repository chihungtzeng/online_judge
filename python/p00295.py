import unittest
import heapq
class MedianFinder(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.left = []
        self.right = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        nleft = len(self.left)
        nright = len(self.right)
        if nleft == 0 and nright == 0:
            heapq.heappush(self.left, -num)
        elif nleft == 1 and nright == 0:
            other = -heapq.heappop(self.left)
            heapq.heappush(self.left, -min(num, other))
            heapq.heappush(self.right, max(num, other))
        elif  nleft == nright:
            temp = [num, -heapq.heappop(self.left), heapq.heappop(self.right)]
            temp.sort()
            heapq.heappush(self.left, -temp[0])
            heapq.heappush(self.left, -temp[1])
            heapq.heappush(self.right, temp[2])
        else:
            temp = [num, -heapq.heappop(self.left), heapq.heappop(self.right)]
            temp.sort()
            heapq.heappush(self.left, -temp[0])
            heapq.heappush(self.right, temp[1])
            heapq.heappush(self.right, temp[2])

    def findMedian(self):
        """
        :rtype: float
        """
        nleft = len(self.left)
        nright = len(self.right)
        if nleft == nright:
            ell = -heapq.heappop(self.left)
            r = heapq.heappop(self.right)
            m = (ell + r) / 2.0
            heapq.heappush(self.left, -ell)
            heapq.heappush(self.right, r)
        else:
            m = -heapq.heappop(self.left)
            heapq.heappush(self.left, -m)
        return m

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = MedianFinder()
        sol.addNum(1)
        self.assertEqual(sol.findMedian(), 1)
        sol.addNum(2)
        self.assertEqual(sol.findMedian(), 1.5)
        sol.addNum(3)
        self.assertEqual(sol.findMedian(), 2)
        sol.addNum(5)
        self.assertEqual(sol.findMedian(), 2.5)
        sol.addNum(11)
        sol.addNum(11)
        sol.addNum(11)
        self.assertEqual(sol.findMedian(), 5)
        sol.addNum(11)
        sol.addNum(11)
        self.assertEqual(sol.findMedian(), 11)


if __name__ == "__main__":
    unittest.main()
