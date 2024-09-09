import unittest
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        nheight = len(height)
        lm = [0 for _ in range(nheight)]
        rm = [0 for _ in range(nheight)]
        for i in range(1, nheight):
            i_1 = i - 1
            lm[i] = max(lm[i_1], height[i_1])
        for i in range(nheight - 2, -1, -1):
            i_1 = i + 1
            rm[i] = max(rm[i_1], height[i_1])
        ret = 0
        for i in range(nheight):
            ret += max(min(lm[i], rm[i]) - height[i], 0)
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.trap([0,1,0,2,1,0,1,3,2,1,2,1]), 6)

if __name__ == "__main__":
    unittest.main()
