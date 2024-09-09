import unittest
class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        import heapq
        neg_stones = [-_ for _ in stones]
        heapq.heapify(neg_stones)
        while len(neg_stones) >= 2:
            s1 = heapq.heappop(neg_stones)
            s2 = heapq.heappop(neg_stones)
            after = -abs(s1 - s2)
            if after != 0:
                heapq.heappush(neg_stones, after)
        if len(neg_stones) == 0:
            return 0
        else:
            return -heapq.heappop(neg_stones)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.lastStoneWeight([2,7,4,1,8,1]), 1)

if __name__ == "__main__":
    unittest.main()
