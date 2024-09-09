import unittest
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        lmask = (1 << 31) & 0xffffffff
        rmask = 1
        ret = 0
        while lmask > rmask:
            nl = n & lmask
            nr = n & rmask
            nl = nl ^ nr
            nr = nl ^ nr
            nl = nl ^ nr
            ret |= (nr | nl)
            lmask >>= 1
            rmask <<= 1
            print(ret)
        return ret


class SolTest(unittest.TestCase):
    def test_1(self):
        n = int("00000010100101000001111010011100", 2)
        m = int("00111001011110000010100101000000", 2)
        sol= Solution()
        self.assertEqual(sol.reverseBits(n), m)

unittest.main()
