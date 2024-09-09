
_UB = (1 << 31) - 1
_LB = -(1 << 31)

class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if (x > _UB) or (x < _LB) or (x == 0):
            return 0
        negative = bool(x < 0)
        absx = abs(x)
        digits = []
        while absx > 0:
            digits.append(absx % 10)
            absx = absx // 10
        ret = 0
        start = 0
        while digits[start] == 0 and start < len(digits):
            start += 1
        for d in digits[start:]:
            ret = (ret << 3) + (ret << 1) + d
        if negative:
            ret *= -1
        if (ret > _UB) or (ret < _LB):
            return 0
        return ret

if __name__ == "__main__":
    sol = Solution()
    print(sol.reverse(123))
    print(sol.reverse(-123))
    print(sol.reverse(120))
    print(sol.reverse(-(2**31)))
    print(sol.reverse(-(2**31 + 1)))
    print(sol.reverse(2**31 -1))
    print(sol.reverse(2**31))
    print(sol.reverse(0))
    assert 0 == sol.reverse(1534236469)
