import unittest
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        d = {}
        for n in nums:
            d[n] = 1 + d.get(n, 0)
        return [_ for _ in d if d[_] == 1]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        ret = sol.singleNumber([1,2,1,3,2,5])
        self.assertEqual(set(ret), set([3,5]))

if __name__ == "__main__":
    unittest.main()
