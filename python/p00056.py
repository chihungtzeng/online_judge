import unittest
class Solution(object):
    def _can_merge(self, s1, s2):
        return bool(s1[1] >= s2[0])

    def _merge(self, s1, s2):
        return [s1[0], max(s1[1], s2[1])]

    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        if not intervals:
            return []
        intervals.sort()
        ret = [intervals[0]]
        for i in range(1, len(intervals)):
            s1 = ret.pop()
            s2 = intervals[i]
            if self._can_merge(s1, s2):
                ret.append(self._merge(s1, s2))
            else:
                ret.append(s1)
                ret.append(s2)
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        ints = [[1,3],[2,6],[8,10],[15,18]]
        self.assertEqual([[1,6],[8,10],[15,18]], sol.merge(ints))
        ints = [[1,4],[4,5]]
        self.assertEqual([[1,5]], sol.merge(ints))

unittest.main()
