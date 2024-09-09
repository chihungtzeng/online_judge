class Solution(object):
    def kClosest2_org(self, points, K):
        import heapq
        res = []
        for p in points:
            dist2 = p[0]*p[0] + p[1]*p[1]
            if len(res) < K:
                heapq.heappush(res, (-dist2, p))
            else:
                far = heapq.heappop(res)
                if -far[0] > dist2:
                    heapq.heappush(res, (-dist2, p))
                else:
                    heapq.heappush(res, far)
        return [_[1] for _ in res]

    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        import heapq
        res = []
        for p in points:
            dist2 = p[0]*p[0] + p[1]*p[1]
            heapq.heappush(res, (-dist2, p))
        while len(res) > K:
            heapq.heappop(res)

        return [_[1] for _ in res]

sol = Solution()
print(sol.kClosest([[1,3],[-2,2]], 1))
print(sol.kClosest([[3,3],[5,-1],[-2,4]], 2))
print(sol.kClosest([[3,3],[5,-1],[-2,4]], 1))

