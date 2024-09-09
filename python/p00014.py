class Solution(object):
    def __common_char(self, strs, index, char):
        for s in strs:
            if len(s) <= index or s[index] != char:
                return False
        return True

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        ret = ""
        if strs:
            for index, char in enumerate(strs[0]):
                if self.__common_char(strs, index, char):
                    ret += char
                else:
                    break
        return ret

if __name__ == "__main__":
    sol = Solution()
    assert "fl" == sol.longestCommonPrefix(["flower","flow","flight"])
    assert "" == sol.longestCommonPrefix(["dog","racecar","car"])
    assert "a" == sol.longestCommonPrefix(["aa","a"])
