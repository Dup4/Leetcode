from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.insert(0, 0)
        cost.append(0)
        n = len(cost)
        f = [0x3f3f3f3f for i in range(n)]
        f[0] = 0
        for i in range(n):
            if i + 1 < n:
                f[i + 1] = min(f[i + 1], f[i] + cost[i])
            if i + 2 < n:
                f[i + 2] = min(f[i + 2], f[i] + cost[i])

        return f[-1]
