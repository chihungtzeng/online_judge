import unittest
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n = len(ratings)
        res = [1] * len(ratings)
        for i in range(n - 1):
            right = i + 1
            if ratings[i] > ratings[right]:
                res[i] = res[right] + 1
        print(res)
        for i in range(n - 1, 0, -1):
            left = i - 1
            if ratings[left] > ratings[i]:
                res[left] = res[i] + 1
        print(res)
        return sum(res)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.candy([1,0,2]), 5)
        self.assertEqual(sol.candy([1,2,2]), 4)

    def test_2(self):
        sol = Solution()
        self.assertEqual(sol.candy([1,2,87,87,87,2,1]), 13)

unittest.main()
