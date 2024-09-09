import unittest
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        res = 0
        ps = [prices[_] for _ in range(len(prices)) if _ == 0 or prices[_] != prices[_-1]]
        n = len(ps)
        if n <= 1:
            return 0
        buy = ps[0] if ps[0] < ps[1] else -1
        for i in range(1, n-1):
            prev = ps[i-1]
            cur = ps[i]
            next_ = ps[i+1]
            if cur > prev and cur > next_:
                res += cur - buy
                buy = -1
            elif cur < prev and cur < next_:
                buy = cur
        if buy >= 0:
            res += ps[n-1] - buy
        return res

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.maxProfit([7,1,5,3,6,4]), 7)
        self.assertEqual(sol.maxProfit([1,2,3,4,5]), 4)
        self.assertEqual(sol.maxProfit([7,6,4,3,1]), 0)
        self.assertEqual(sol.maxProfit([7,1,2,2,5,5,5,3]), 4)
        self.assertEqual(sol.maxProfit([7,1,2,2,5,5,5,3,3,3,6]), 7)
        self.assertEqual(sol.maxProfit([2,1,2,0,1]), 2)

unittest.main()
