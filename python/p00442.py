import unittest
class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        for i in range(len(nums)):
            n = abs(nums[i])
            if nums[n-1] > 0:
                nums[n-1] *= -1
            else:
                ret.append(n)
        return ret

class Solution2(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        return [n for i, n in enumerate(nums) if i > 0 and nums[i] == nums[i-1]]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.findDuplicates([4,3,2,7,8,2,3,1]),[2,3])
        self.assertEqual(sol.findDuplicates([1]),[])


if __name__ == "__main__":
    unittest.main()
