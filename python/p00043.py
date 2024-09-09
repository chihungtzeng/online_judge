import unittest
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == "0" or num2 == "0":
            return "0"
        ret = [0] * (len(num1) + len(num2))
        s1 = num1[::-1]
        s2 = num2[::-1]
        for i in range(len(s1)):
            d1 = int(s1[i])
            for j in range(len(s2)):
                ret[i+j] += d1 * int(s2[j])
        carry = 0
        for i in range(len(ret)):
            v = ret[i] + carry
            carry = v / 10
            ret[i] = v % 10
        done = False
        while not done:
            if ret[-1] == 0:
                ret.pop()
            else:
                done = True
        res = ""
        for i in range(len(ret) -1, -1, -1):
            res += str(ret[i])

        return res

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.multiply("123", "456"), "56088")
        self.assertEqual(sol.multiply("31415926", "2718283456782"), "85397391925287510132")
        self.assertEqual(sol.multiply("31415926", "1"), "31415926")
        self.assertEqual(sol.multiply("31415926", "0"), "0")

unittest.main()
