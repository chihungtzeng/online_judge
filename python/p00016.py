import unittest
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        import bisect
        diff = float("inf")
        nums.sort()
        ret = -100
        nlen = len(nums)
        for i in range(nlen - 2):
            for j in range(i+1, nlen - 1):
                sum2 = nums[i] + nums[j]
                lookfor = target - sum2
                index = bisect.bisect_left(nums[j+1:], lookfor)
                if index > 0 and index + j < nlen:
                    sum3 = sum2 + nums[index + j]
                    if abs(sum3 - target) < diff:
                        ret = sum3
                        diff = abs(sum3 - target)
                if index + j + 1 < nlen:
                    sum3 = sum2 + nums[index + j + 1]
                    if abs(sum3 - target) < diff:
                        ret = sum3
                        diff = abs(sum3 - target)
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.threeSumClosest([-1, 2, 1, -4], 1), 2)

if __name__ == "__main__":
    unittest.main()
