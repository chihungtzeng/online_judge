import unittest
class Solution(object):
    def _can_merge(self, s1, s2):
        return bool(s1[1] >= s2[0])

    def _merge(self, s1, s2):
        return [s1[0], max(s1[1], s2[1])]

    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        if not intervals:
            return [newInterval]

        inserted = False
        for i in range(len(intervals)):
            if newInterval[0] < intervals[i][0]:
                intervals.insert(i, newInterval)
                inserted = True
                break
        if not inserted:
            intervals.append(newInterval)

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
        ints = [[1,3],[6,9]]
        self.assertEqual(sol.insert(ints, [2,5]), [[1,5],[6,9]])

        ints = [[1,2],[3,5],[6,7],[8,10],[12,16]]
        expected = [[1,2],[3,10],[12,16]]
        self.assertEqual(sol.insert(ints, [4,8]), [[1,2],[3,10],[12,16]])
    def test_2(self):
        sol = Solution()
        ints = []
        self.assertEqual(sol.insert(ints, [5,7]), [[5,7]])

    def test_3(self):
        sol = Solution()
        ints = [[1,5]]
        self.assertEqual(sol.insert(ints, [2,7]), [[1,7]])
        ints = [[1,5]]
        self.assertEqual(sol.insert(ints, [0, 3]), [[0,5]])
        ints = [[1,5],[6,8]]
        self.assertEqual(sol.insert(ints, [0, 9]), [[0,9]])
        

unittest.main()
