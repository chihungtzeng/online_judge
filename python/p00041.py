import unittest
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = set(nums)
        for i in range(1, len(nums) + 1):
            if i not in s:
                return i
        return len(nums) + 1

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.firstMissingPositive([1,2,0]), 3)
        self.assertEqual(sol.firstMissingPositive([3,4,-1,1]), 2)
        self.assertEqual(sol.firstMissingPositive([7,8,9,11,12]), 1)

unittest.main()        
