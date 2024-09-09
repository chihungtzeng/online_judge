
_INT_MAX = (1 << 31) - 1
_INT_MIN = -(1 << 31)

class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if not str:
            return 0
        idx = self._first_non_space_idx(str)
        ret = 0
        sign = 1
        slen = len(str)
        if idx >= slen:
            return 0
        char = str[idx]
        if char in "+-":
            if char == "-":
                sign = -1
            idx += 1
        while idx < slen:
            if str[idx].isdigit():
                ret = ret * 10 + int(str[idx])
            else:
                break
            idx += 1
        ret = ret * sign
        if ret > _INT_MAX:
            return _INT_MAX
        elif ret < _INT_MIN:
            return _INT_MIN
        return ret

    def _first_non_space_idx(self, s):
        idx = 0
        slen = len(s)
        while idx < slen:
            if s[idx] != " ":
                return idx
            idx += 1
        return idx

if __name__ == "__main__":
    sol = Solution()
    assert 42 == sol.myAtoi("42")
    assert -42 == sol.myAtoi("   -42")
    assert 4193 == sol.myAtoi("4193 with words")
    assert 0 == sol.myAtoi("words and 987")
    assert -2147483648 == sol.myAtoi("-9128347233")
    assert 0 == sol.myAtoi("")
    assert 0 == sol.myAtoi(" ")
