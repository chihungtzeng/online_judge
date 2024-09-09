import unittest
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        import bisect
        tails = [nums[0]]
        for i in range(1, len(nums)):
            n = nums[i]
            index = bisect.bisect_left(tails, n)
            if index < len(tails):
                tails[index] = min(n, tails[index])
            else:
                tails.append(n)
        return len(tails)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.lengthOfLIS([10,9,2,5,3,7,101,18]), 4)

if __name__ == "__main__":
    unittest.main()
