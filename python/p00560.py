import unittest
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        psum = [0] * n
        psum[0] = nums[0]
        for i in range(1, n):
            psum[i] = psum[i-1] + nums[i]
        psum_count = {}
        for p in psum:
            psum_count[p] = 1 + psum_count.get(p, 0)

        res = psum_count.get(k, 0)
        for i in range(0, n):
            if k == 0:
                res += psum_count[psum[i]] - 1
            else:
                target = psum[i] + k
                res += psum_count.get(target, 0)
            psum_count[psum[i]] -= 1
        return res

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.subarraySum([1,1,1], 2), 2)
        self.assertEqual(sol.subarraySum([1,2,3,4,5], 5), 2)
        self.assertEqual(sol.subarraySum([1,-1,1,-1], 0), 4)
        self.assertEqual(sol.subarraySum([1,-1,1,-1,1,-1], 0), 9)

unittest.main()
