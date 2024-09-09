import unittest
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        if numCourses == 1:
            return True

        pres = {_ : [] for _ in range(numCourses)}
        in_degrees = [0 for _ in range(numCourses)]
        for course, pre in prerequisites:
            pres[course].append(pre)
            in_degrees[pre] += 1
        srcs = []
        extracted = [0 for _ in range(numCourses)]
        for course in range(numCourses):
            if in_degrees[course] == 0:
                srcs.append(course)
        while srcs:
            src = srcs.pop(-1)
            for dep in pres[src]:
                in_degrees[dep] -= 1
                if in_degrees[dep] == 0:
                    srcs.append(dep)
        for course in in_degrees:
            if in_degrees[course] > 0:
                return False
        return True


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertTrue(sol.canFinish(2, [[1,0]] ))
        self.assertFalse(sol.canFinish(2, [[1,0],[0,1]]))

if __name__ == "__main__":
    unittest.main()
