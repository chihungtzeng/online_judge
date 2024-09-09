import unittest
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_d = {_ : 0 for _ in nums}
        ret = 0
        for n in nums:
            if n - 1 in nums_d:
                continue
            end = n + 1
            while end in nums_d:
                end += 1
            ret = max(ret, end - n)
        return ret


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        nums = [100, 4, 200, 1, 3, 2]
        self.assertEqual(sol.longestConsecutive(nums), 4)
        
        nums2 = nums + list(range(1000, 1100))
        self.assertEqual(sol.longestConsecutive(nums2), 100)

if __name__ == "__main__":
    unittest.main()
