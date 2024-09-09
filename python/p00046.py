import unittest
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []
        nelem = len(nums)
        if nelem == 1:
            return [[nums[0]]]
        ret = []
        for i in range(nelem):
            tmp_nums = nums[0:i] + nums[i+1:]
            res = self.permute(tmp_nums)
            for item in res:
                item.append(nums[i])
                ret.append(item)
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        print(sorted(sol.permute([1,2,3])))

unittest.main()
