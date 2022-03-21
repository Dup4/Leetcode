from bisect import bisect_left, bisect_right
from typing import List


class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        S = sum(nums) + 1

        def get(x: int):
            cur = 0
            res = 1
            for a in nums:
                if cur + a > x:
                    cur = 0
                    res += 1
                cur += a
            return -res

        return bisect_left(range(S + 1), -m, max(nums), S + 1, key=get)
