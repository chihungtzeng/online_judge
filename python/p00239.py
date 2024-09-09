import unittest
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        last = -1
        ret = []
        if not nums:
            return ret
        lm = -float("inf")
        for i in range(k):
            if nums[i] >= lm:
                lm = nums[i]
                last = i
        ret.append(lm)
        for right in range(k, len(nums)):
            left = right -k + 1
            if last >= left:
                if nums[right] >= lm:
                    lm = nums[right]
                    last = right
                else:
                    lm = ret[-1]
            else:
                lm = -float("inf")
                for i in range(left, right+1):
                    if nums[i] >= lm:
                        lm = nums[i]
                        last = i
            ret.append(lm)
        return ret

class SOlTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        expected = [3,3,5,5,6,7]
        self.assertEqual(sol.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3), expected)
        self.assertEqual(sol.maxSlidingWindow([], 0), [])

if __name__ == "__main__":
    unittest.main()
