import unittest
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        anas = {}
        for s in strs:
            ss = "".join(sorted(s))
            if ss in anas:
                anas[ss].append(s)
            else:
                anas[ss] = [s]
        return [anas[_] for _ in anas]

sol = Solution()
print(sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))

