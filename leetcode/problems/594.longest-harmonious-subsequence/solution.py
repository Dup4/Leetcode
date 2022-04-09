from typing import Counter, List


class Solution:
    def findLHS(self, nums: List[int]) -> int:
        a = Counter(nums)
        res = 0
        for k, v in a.items():
            if (k - 1) in a.keys():
                res = max(res, v + a[k - 1])
        return res
