class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_codes = {}
        orda = ord("A")
        for code in range(orda, ord("Z") + 1):
            char_codes[chr(code)] = code - orda + 1
        ret = 0
        for char in s:
            ret = ret * 26 + char_codes[char]
        return ret

sol = Solution()
print(sol.titleToNumber("A"))
print(sol.titleToNumber("AB"))
print(sol.titleToNumber("ZY"))
