import unittest
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        ret = [0] * (1 + num)
        for n in range(1, num+1):
            ret[n] = ret[n >> 1] + (n & 1)
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(s.countBits(5), [0,1,1,2,1,2])

if __name__ == "__main__":
    unittest.main()
