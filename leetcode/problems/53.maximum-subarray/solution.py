from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = -10000
        cur = 0
        for a in nums:
            cur += a
            res = max(res, cur)
            if cur < 0:
                cur = 0
        return res
